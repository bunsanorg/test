macro(bunsan_testing_project_header)
    bunsan_tests_project_header()
    bunsan_use_bunsan(testing)
endmacro()

macro(bunsan_testing_project_aux_add_tests)
    bunsan_tests_project_aux_add_tests()
endmacro()

macro(bunsan_testing_project_footer)
    bunsan_tests_project_footer()
endmacro()

macro(bunsan_testing_project)
    bunsan_testing_project_header()
    bunsan_testing_project_aux_add_tests()
    bunsan_testing_project_footer()
endmacro()
