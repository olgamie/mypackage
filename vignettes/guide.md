---
output: pdf_document
---
<!--
%\VignetteEngine{knitr::knitr}
%\VignetteIndexEntry{An Introduction to the mypackage}
-->
   
   An Introduction to **mypackage** package
=======================================
   



Introduction
------------
   
   
   The  **mypackage** package is a solution of homework 6 of Advanced Data Analysis Software Development with R



Functions:
----------------------------
   There are three functions included in the package:

- mode - returns most frequent value from given integer vector
- simplify2array - mimics the behaviour of simplify2array from base package
- ass - generates all possible 0-1 assignment vectors of _2n_ survey participants in such a way that exactly n of them are assigned to group 0 (control) and the other n ones are assigned to group 1 (treatment).

Examples
-----------------------------


```r
mode(c(1,2,5,5,45,732,24,1,3,4,5,732,4,63))
```

```
## [1] 5
```

```r
simplify2array(list(1:4, 4:7))
```

```
##      [,1] [,2]
## [1,]    1    4
## [2,]    2    5
## [3,]    3    6
## [4,]    4    7
```

```r
ass(2)
```

```
##      [,1] [,2] [,3] [,4]
## [1,]    0    0    1    1
## [2,]    0    1    0    1
## [3,]    0    1    1    0
## [4,]    1    0    0    1
## [5,]    1    0    1    0
## [6,]    1    1    0    0
```
