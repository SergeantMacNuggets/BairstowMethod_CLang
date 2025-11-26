switch(func->degree) {
        //     // case 3:
        //     //     sheet->roots[0] = get_quadratic_root(func, ADD);
        //     //     sheet->roots[1] = get_quadratic_root(func, ADD);
        //     //     break;
        //     case 4:
        //         sheet->roots[2] = shift_solve(shorten_func);
        //         break;
        //     case 5:
        //         sheet->roots[2] = get_quadratic_root(table->middle_func, ADD);
        //         sheet->roots[3] = get_quadratic_root(table->middle_func, SUBSTRACT);
        //         break;
        //     case 6:
        //         shorten_func->degree = func->degree - 2;
        //         *sheet->tables = create_table(table->u_k1, table->v_k1, shorten_func);
        //         loop(sheet, shorten_func, tolerance);
        //         table = *sheet->tables;
        //         if (table) {
        //             Polynomial *quadratic2 = create_quadtratic(1, table->u_k1, table->v_k1);
        //             if (quadratic2) {
        //                 sheet->roots[2] = get_quadratic_root(quadratic2, ADD);
        //                 sheet->roots[3] = get_quadratic_root(quadratic2, SUBSTRACT);
        //                 sheet->roots[4] = shift_solve(fetch_left_func(table->middle_func));
        //                 free(quadratic2);
        //             }
        //         }
        //         break;
        // }