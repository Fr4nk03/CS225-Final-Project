// #include <iostream>
// #include <unordered_map>
// #include <vector>

// // Class to represent a page in the web
// class Page {
// public:
//   // Constructor
//   Page(int id) : id_(id) {}

//   // Getters
//   int id() const { return id_; }
//   double PageRank() const { return PageRank_; }
//   const std::vector<Page*>& links() const { return links_; }

//   // Setters
//   void set_PageRank(double PageRank) { PageRank_ = PageRank; }

//   // Methods
//   void AddLink(Page* page) { links_.push_back(page); }

// private:
//   // The page's ID
//   int id_;

//   // The page's PageRank value
//   double PageRank_;

//   // The pages that this page links to
//   std::vector<Page*> links_;
// };

// // Class to represent the web of products
// class Web {
// public:
//   // Constructor
//   Web() : pages_() {}

//   // Getters
//   const std::unordered_map<int, Page*>& pages() const { return pages_; }

//   // Methods
//   void AddPage(Page* page) { pages_[page->id()] = page; }
//   void AddLink(int source_id, int target_id) {
//     Page* source = pages_[source_id];
//     Page* target = pages_[target_id];
//     source->AddLink(target);
//   }
//   void ComputePageRanks(double damping_factor, int num_iterations);

// private:
//   // The pages in the web
//   std::unordered_map<int, Page*> pages_;
// };

// #include "utility.h"
// #include "Graph.h"

// // Method to compute the PageRank values for all pages in the web
// void Graph::ComputePageRanks(double damping_factor, int num_iterations) {
//   // Initialize the PageRank values to 1.0
// //   for (const auto& page_pair : pages_) {
// //     page_pair.second->set_PageRank(1.0);
// //   }
//     for (const auto& product : vertices) {
//         // vector<Edge> edge = product.second;
//         // for (Edge e : edge) {
//         //     e.from.set_PageRank(1.0);
//         //     e.to.set_PageRank(1.0);
//         // }
//         product,set_PageRank(1.0);
//     }



// //   // Perform the specified number of iterations of the PageRank algorithm
// //   for (int i = 0; i < num_iterations; ++i) {
// //     // For each page in the web, compute its new PageRank value
// //     for (const auto& page_pair : pages_) {
// //       Page* page = page_pair.second;
// //       double sum = 0.0;
// //       for (Page* link : page->links()) {
// //         sum += link->PageRank() / link->links().size();
// //       }
// //       page->set_PageRank((1.0 - damping_factor) + damping_factor * sum);
// //     }
// //   }

//   for (int i = 0; i < num_iterations; ++i) {
//     // For each page in the web, compute its new PageRank value
//     for (const auto& product : vertices) {
//       Product p = product.first;
//       double sum = 0.0;
//       Edge edge = product.second;
//       for (Product link : p.links_) {
//         sum += link.PageRank() / link.links_.size();
//       }
//       p.set_PageRank((1.0 - damping_factor) + damping_factor * sum);
//     }
//   }
// }