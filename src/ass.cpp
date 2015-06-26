#include <Rcpp.h>
#include <algorithm>
#include <vector>
using namespace Rcpp;
using namespace std;

//' @title ass
//' @description
//'   Function generates all possible 0-1 assignment
//' vectors of 2n survey participants in such a way that exactly n of them are assigned to group 0 control
//' and the other n ones are assigned to group 1 treatment.
//'
//' @param r - an integer
//' @return a matrix with 2n columns and an appropriate number of rows.
//'
//' @export
// [[Rcpp::export]]    
NumericMatrix ass(int r) {
  if (r < 0) stop("r < 0");
  int dim;
  int n = 2.0*r;
  if (r * 2.0 > n) r = n-r;
  if (r == 0) dim = 1.0;
  
  dim = n;
  for( int i = 2; i <= r; ++i ) {
    dim *= (n-i+1);
    dim /= i;
  }
  
  std::vector<bool> v(n);
  std::fill(v.begin() + n - r, v.end(), true);
  NumericMatrix mat(dim, n);
  int j = 0;    
  do {
    for (int i = 0; i < n; ++i) {        
      if (v[i]) {
        mat(j,i) = 1;
      }           
    }
    ++j;
  } while (std::next_permutation(v.begin(), v.end()));
  return mat;
}