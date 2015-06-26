#include <Rcpp.h>
using namespace Rcpp ;

//' @title mode
//' @description
//'   Function returs a value that appears most often in a set of data.
//'
//' @param x - an integer vector
//' @return The most frequently occuring value.
//'
//' @export
//[[Rcpp::export]]
int mode (const IntegerVector x) {
  if (x.size() == 0) return NA_INTEGER;
  
  //IntegerVector y = clone(x);
  //std::sort(y.begin(), y.end());
  IntegerVector y = clone(x).sort();
  
  int count = 1;
  int max_count = 1;
  int max_val = y[0];
  
  for (int i = 1; i < y.size(); i++){
    if(y[i-1] == y[i]){
      count++;
      
      if(max_count < count) {
        max_count = count;
        max_val = y[i];
      }} else {
        count = 1;
      }
  }
  return max_val;
}