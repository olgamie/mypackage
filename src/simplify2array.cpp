#include <Rcpp.h>
using namespace Rcpp ;

//' @title simplify2array
//' @description
//'   Function mimics behavior of simplify2array from base when higher = T
//'
//' @param x - List of numeric vectors
//' @return Simplified matrix
//'
//' @export
//[[Rcpp::export]]
NumericMatrix simplify2array(List x) {

  NumericVector vec = x[0];
  int row = vec.size();
  int col = x.size();
  
  NumericMatrix mat(row, col);
  for (int i = 0; i < col; i++){
    vec = x[i];
    if(row != vec.size()) stop("length of list elements differ");
    for (int n = 0; n < row; n++){
      mat(n, i) = vec[n];
    }
  }
  return mat;
}