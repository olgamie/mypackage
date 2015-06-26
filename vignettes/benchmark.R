## ---- include=FALSE------------------------------------------------------
require(mypackage)
require(microbenchmark)
require(combinat)

## ------------------------------------------------------------------------
mode2 <- function(x) {
  m <- unique(x)
  m[which.max(tabulate(match(x, m)))]
}

## ---- cache=TRUE---------------------------------------------------------
microbenchmark(mode(c(1:1000,1:999,1)), mode2(c(1:1000,1:999,1)))
microbenchmark(mode(c(1:1000,1:1000,1:1000,1)), mode2(c(1:1000,1:1000,1:1000,1)))
microbenchmark(mode(c(1:100000,100000:1,1)), mode2(c(1:100000,100000:1,1)))

## ---- cache=TRUE---------------------------------------------------------
microbenchmark(base::simplify2array(list(1:10000000,1:10000000)), mypackage::simplify2array(list(1:10000000,1:10000000)))

microbenchmark(base::simplify2array(list(1:10000,1:10000)), mypackage::simplify2array(list(1:10000,1:10000)))

## ------------------------------------------------------------------------
ass2 <- function(x) {
  n = 2*x
  mat <- t(combn(n,x))
  matr <- matrix(0,nrow(mat),n)
  
  for (i in 1:nrow(matr)){
    matr[i,mat[i,]] <- 1
  }
  matr
}

## ---- cache=TRUE---------------------------------------------------------
microbenchmark(ass(3), ass2(3))
microbenchmark(ass(8), ass2(8))

