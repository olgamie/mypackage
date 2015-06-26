<!--
%\VignetteEngine{knitr::knitr}
%\VignetteIndexEntry{Benchmarks of functions from h6 package}
-->

  Benchmarking functions from **mypackage** package
=======================================




Mode
------------

Let's construct a mode function in R and call it **mode2**:

```r
mode2 <- function(x) {
  m <- unique(x)
  m[which.max(tabulate(match(x, m)))]
}
```

Results on different input data:


```r
microbenchmark(mode(c(1:1000,1:999,1)), mode2(c(1:1000,1:999,1)))
```

```
## Unit: microseconds
##                        expr     min      lq     mean   median       uq
##   mode(c(1:1000, 1:999, 1)) 143.287 146.051 152.4138 149.0115 154.5375
##  mode2(c(1:1000, 1:999, 1)) 160.261 163.419 207.5536 169.3395 185.5235
##       max neval
##   196.576   100
##  1242.216   100
```

```r
microbenchmark(mode(c(1:1000,1:1000,1:1000,1)), mode2(c(1:1000,1:1000,1:1000,1)))
```

```
## Unit: microseconds
##                                 expr     min      lq     mean   median
##   mode(c(1:1000, 1:1000, 1:1000, 1)) 137.367 141.709 157.9243 145.0645
##  mode2(c(1:1000, 1:1000, 1:1000, 1)) 208.813 211.970 253.5239 223.6155
##        uq      max neval
##  152.5640 1109.586   100
##  231.1155 1245.373   100
```

```r
microbenchmark(mode(c(1:100000,100000:1,1)), mode2(c(1:100000,100000:1,1)))
```

```
## Unit: milliseconds
##                           expr      min       lq     mean   median
##   mode(c(1:1e+05, 1e+05:1, 1)) 21.96159 22.62138 23.81802 23.43294
##  mode2(c(1:1e+05, 1e+05:1, 1)) 17.02628 18.67961 26.85840 19.75209
##        uq      max neval
##  24.13398 62.18417   100
##  21.74606 66.23449   100
```

**mode** from **mypackage** outperforms **mode2**.

simplify2array:
----------------------------
The goal was to build a function that whould mimic the behaviour of simplify2array from package base. The comparison will be done between **base::simplify2array** and **mypacage::simplify2array**

```r
microbenchmark(base::simplify2array(list(1:10000000,1:10000000)), mypackage::simplify2array(list(1:10000000,1:10000000)))
```

```
## Unit: milliseconds
##                                               expr      min       lq
##       base::simplify2array(list(1:1e+07, 1:1e+07)) 276.6701 296.5945
##  mypackage::simplify2array(list(1:1e+07, 1:1e+07)) 181.2367 202.2783
##      mean   median       uq      max neval
##  319.1556 309.8906 341.8682 437.5585   100
##  230.5421 229.5346 246.9280 364.1320   100
```

```r
microbenchmark(base::simplify2array(list(1:10000,1:10000)), mypackage::simplify2array(list(1:10000,1:10000)))
```

```
## Unit: microseconds
##                                               expr     min       lq
##       base::simplify2array(list(1:10000, 1:10000)) 304.338 311.4425
##  mypackage::simplify2array(list(1:10000, 1:10000))  86.842 148.0250
##      mean  median      uq     max neval
##  335.0040 329.206 345.192 481.571   100
##  165.2347 152.761 170.721 256.575   100
```

**simplify2array** from **mypackage** outperforms **simplify2array** from **base**.

ass:
----------------------------
The goal was to build a function that whould mimic the behaviour of simplify2array from package base. The comparison will be done between **base::simplify2array** and **mypacage::simplify2array**


```r
ass2 <- function(x) {
  n = 2*x
  mat <- t(combn(n,x))
  matr <- matrix(0,nrow(mat),n)
  
  for (i in 1:nrow(matr)){
    matr[i,mat[i,]] <- 1
  }
  matr
}
```


```r
microbenchmark(ass(3), ass2(3))
```

```
## Unit: microseconds
##     expr     min       lq      mean  median       uq     max neval
##   ass(3)   3.158   3.9480   5.81515   5.527   7.1060  30.394   100
##  ass2(3) 220.260 232.8915 251.16739 239.207 257.3645 747.225   100
```

```r
microbenchmark(ass(8), ass2(8))
```

```
## Unit: milliseconds
##     expr        min         lq       mean     median        uq        max
##   ass(8)   1.679576   1.714905   1.775444   1.744905   1.79543   2.362854
##  ass2(8) 104.091455 108.630651 114.303038 112.289402 116.60400 153.231378
##  neval
##    100
##    100
```

**ass** from **mypackage** outperforms **ass2**.
