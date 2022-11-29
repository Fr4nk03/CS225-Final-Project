//sparce matrix (CSR format)
#ifndef CSR_H
#define CSR_H

#include <vector>
#include "util.h"
using namespace std;

// Matrix entry.
class Entry { //empty val = 0 because every product id > 0
public:
    Entry(int r, int c): row(r), col(c), val(), isEmpty(true) {} //no entry value
    Entry(int r, int c, int v): row(r), col(c), val(v), isEmpty(false) {} //has entry value

    int R() { return row; }
    int C() { return col; }
    int V() { return val; }
    bool IsEmpty() { return isEmpty; }

    void SetEmpty() { isEmpty = true; val = 0; }
    void SetVal(int v) { isEmpty = false; val = v; }

private:
    int row;         // row index
    int col;         // column index
    int val;       // entry value
    bool isEmpty;  //no entry if true
};

//CSR (Compressed Sparse Row) format
class Csr {
public:
    Csr(int m, int n): m(m), n(n), entry(), rowId(m + 1), colId() {}

    int M() { return m; }
    int N() { return n; }
    vector<Entry*> entry() { return entry; }
    vector<int> RowId() { return rowId; }
    vector<int> ColId() { return colId; }

    // Get an element at (i, j).
    Entry* Get(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            throw out_of_range("check your coordinates!");
        }
        for (int pos = ia_[i]; pos < ia_[i + 1]; ++pos) {
            if (ja_[pos] == j) {
                return a_[pos];
            }
        }
        // If there's no match, return a new empty entry.
        return new Entry(i, j);
    }

    // Get all nonempty entries at row.
    vector<Entry<T>*> GetRow(int i) {
        if (i < 0 || i >= m_) {
            throw out_of_range("invalid row number");
        }
        vector<Entry<T>*> row;
        for (int pos = ia_[i]; pos < ia_[i + 1]; ++pos) {
            row.push_back(a_.at(pos));
        }
        return row;
    }

    // Set an element at (i, j) with v.
    void Set(int i, int j, T v) {
        if (i < 0 || i >= m_ || j < 0 || j >= n_) {
            throw out_of_range("invalid coordinates (i, j)");
        }
        int pos = ia_[i];   // column index position;
        int col = -1;       // column index, initially invalid;
        if (ia_[i + 1] > ia_[i]) {
            pos = ia_[i + 1] - 1;
            col = ja_[pos];
        }
        if (col != j) {
            if (a_.empty()) {
                a_.push_back(new Entry<T>(i, j, v));
                ja_.push_back(j);
            } else {
                a_.insert(a_.begin() + pos, new Entry<T>(i, j, v));
                ja_.insert(ja_.begin() + pos, j);               
            }
            for (int r = i + 1; r <= m_; ++r) {
                ia_[r] += 1;
            }
        } else {
            // Set a different value to an existing entry.
            a_[pos]->SetV(v);
        }
    }

private:
    int m; // number of rows
    int n; // number of columns

    vector<Entry*> entry;  // nonzero entries
    vector<int> rowId;     // row indices
    vector<int> colId;     // column indices
};

#endif