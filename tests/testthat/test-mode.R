test_that(
  "Testing function: mode",
  {
   expect_error(mode("LA"))
   expect_error(mode(list("LA", 1:3)))
   expect_equal(mode(numeric(0)), NA_integer_)
   expect_equal(mode(NA_integer_), NA_integer_)
   expect_equal(mode(1),1)
   expect_equal(mode(rep(1,10)),1)
   expect_equal(mode(c(1:10,1)),1)
   expect_equal(mode(c(rep(2,10),rep(3,10))),2)
   expect_equal(mode(c(rep(NA,10), rep(1,9))), NA_integer_)
   expect_is(mode(1), "integer")
  })
