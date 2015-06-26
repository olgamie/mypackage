test_that(
  "Testing function: ass",
  {
    expect_error(ass("LA"))
    expect_error(ass(list("LA", 1:3)))
    expect_error(ass(c(1,2)))
    expect_equal(ass(1), matrix(c(0:1, 1:0), 2,2))
    expect_equal(length(ass(3)), 120)
    expect_is(ass(3), "matrix")
    expect_error(ass(-1))
  })
