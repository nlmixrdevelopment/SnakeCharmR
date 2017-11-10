#include <R.h>
#include <Rinternals.h>
#include <Rmath.h> //Rmath includes math.
#include <R_ext/Rdynload.h>

SEXP _SnakeCharmR_rcpp_Py_Initialize();
SEXP _SnakeCharmR_rcpp_Py_Finalize();
SEXP _SnakeCharmR_rcpp_Py_run_code(SEXP codeSEXP);
SEXP _SnakeCharmR_rcpp_Py_get_var(SEXP varnameSEXP);

// fix R check warning as per https://github.com/RcppCore/Rcpp/issues/636#issuecomment-280985661
void R_init_SnakeCharmR(DllInfo* info) {
  R_CallMethodDef callMethods[]  = {
    {"_SnakeCharmR_rcpp_Py_Initialize", (DL_FUNC) &_SnakeCharmR_rcpp_Py_Initialize, 0},
    {"_SnakeCharmR_rcpp_Py_Finalize", (DL_FUNC) &_SnakeCharmR_rcpp_Py_Finalize, 0},
    {"_SnakeCharmR_rcpp_Py_run_code", (DL_FUNC) &_SnakeCharmR_rcpp_Py_run_code, 1},
    {"_SnakeCharmR_rcpp_Py_get_var", (DL_FUNC) &_SnakeCharmR_rcpp_Py_get_var, 1},
    {NULL, NULL, 0}
  };
  R_registerRoutines(info, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(info, FALSE);
}
