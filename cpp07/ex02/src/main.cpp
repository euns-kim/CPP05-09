/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:36:54 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/17 15:02:43 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

int main(void)
{
    {
        Array<int>  *int_arr = new Array<int>(5);

        try {
            (*int_arr)[0] = 0;
            (*int_arr)[1] = 1;
            (*int_arr)[2] = 2;
            (*int_arr)[3] = 3;
            (*int_arr)[4] = 4;

            int_arr->printArray();
        } catch (std::exception &e) {
            cout << "Exception caught: " << e.what() << endl;
        }
        Array<int>  int_arr_cpy(*int_arr);
        delete int_arr;
        int_arr_cpy.printArray();
    }
    cout << endl;
    {
        Array<float>  float_arr(3);

        try {
            float_arr[0] = 0.0;
            float_arr[1] = 3.0;
            float_arr[2] = 6.0;
			// float_arr[3] = 7.0;

            float_arr.printArray();

            Array<float>    float_arr_2;
            float_arr_2 = float_arr;
            float_arr_2.printArray();
        } catch (std::exception &e) {
            cout << "Exception caught: " << e.what() << endl;
        }
    }
    cout << endl;
    {
        Array<std::string>  str_arr(2);

        try {
            str_arr[0] = "HELLO";
            str_arr[1] = "WORLD";
			// cout << str_arr[2] << endl;

            str_arr.printArray();

            Array<std::string>  str_arr_cpy(str_arr);
            str_arr_cpy.printArray();
        } catch (std::exception &e) {
            cout << "Exception caught: " << e.what() << endl;
        }
    }
    cout << endl;
    {
        Array<double>  dbl_arr;

        try {
            cout << dbl_arr[0] << endl;
        } catch (std::exception &e) {
            cout << "Exception caught: " << e.what() << endl;
        }   
    } // should be protected with exception
	// system("leaks Array");
}