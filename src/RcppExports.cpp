// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// ass
NumericMatrix ass(int r);
RcppExport SEXP mypackage_ass(SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    __result = Rcpp::wrap(ass(r));
    return __result;
END_RCPP
}
// mode
int mode(const IntegerVector x);
RcppExport SEXP mypackage_mode(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< const IntegerVector >::type x(xSEXP);
    __result = Rcpp::wrap(mode(x));
    return __result;
END_RCPP
}
// simplify2array
NumericMatrix simplify2array(List x);
RcppExport SEXP mypackage_simplify2array(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< List >::type x(xSEXP);
    __result = Rcpp::wrap(simplify2array(x));
    return __result;
END_RCPP
}
