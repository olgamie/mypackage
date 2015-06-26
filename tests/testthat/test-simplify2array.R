test_that(
  "Testing function: simplify2array",
  {
    expect_error(simplify2array("LA"))
    expect_error(simplify2array(list("LA", 1:3)))
    expect_equal(simplify2array(list(rep(1,3), rep(1,3))), matrix(1,3,2))
    expect_error(simplify2array(list(1:3, 1:4)))
    expect_error(simplify2array(list(1:4, 1:3)))
    expect_equal(simplify2array(list(1:3, 1:3)), matrix(c(1:3, 1:3), 3,2))
    expect_is(simplify2array(list(1:3, 1:3)), "matrix")
  })
