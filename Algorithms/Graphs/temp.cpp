#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;                 // stdout library for printing values
bool custom_sort(double a, double b) /* this custom sort function is defined to
                                     sort on basis of min absolute value or error*/
{
    double a1 = abs(a - 0);
    double b1 = abs(b - 0);
    return a1 < b1;
}
int main()
{
    /*Intialization Phase*/
    double x1[] = {186, 127, 158, 141, 168, 185, 185, 184, 117, 179, 144, 179, 133, 121, 150, 157, 159, 112, 132, 169, 209, 166, 199, 158, 221};

    double x2[25] = {0};
    for (int i = 0; i < 25; i++)
    {
        x2[i] = 79.558 + 0.66425 * x1[i];
    }
    double y[] = {0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0};

    vector<double> error;  // for storing the error values
    double err;            // for calculating error on each stage
    double b0 = 0;         // initializing b0
    double b1 = 0;         // initializing b1
    double b2 = 0;         // initializing b2
    double alpha = 0.00003329; // initializing our learning rate
    double e = 2.71828;

    /*Training Phase*/
    for (int i = 0; i < 100; i++)
    {                                                        // Since there are 10 values in our dataset and we want to run for 4 epochs so total for loop run 40 times
        int idx = i % 25;                                          // for accessing index after every epoch
        double p = -(b0 + b1 * x1[idx] + b2 * x2[idx]);      // making the prediction
        double pred = 1 / (1 + pow(e, (int)p));                   // calculating final prediction applying sigmoid
        err = y[idx] - pred;                                 // calculating the error
        b0 = b0 - alpha * err * pred * (1 - pred) * 1.0;     // updating b0
        b1 = b1 + alpha * err * pred * (1 - pred) * x1[idx]; // updating b1
        b2 = b2 + alpha * err * pred * (1 - pred) * x2[idx]; // updating b2
        cout << (alpha * err * pred * (1 - pred)) << endl;
        // cout << "B0=" << b0 << " "
        //      << "B1=" << b1 << " "
        //      << "B2=" << b2 << " error=" << err << endl; // printing values after every step
        error.push_back(err);
    }
    sort(error.begin(), error.end(), custom_sort); // custom sort based on absolute error difference
    cout << "Final Values are: "
         << "B0=" << b0 << " "
         << "B1=" << b1 << " "
         << "B2=" << b2 << " error=" << error[0];

    /*Testing Phase*/
    double test1, test2; // enter test x1 and x2
    cin >> test1 >> test2;
    double pred = b0 + b1 * test1 + b2 * test2; // make prediction
    cout << "The value predicted by the model= " << pred << endl;
    if (pred > 0.5)
        pred = 1;
    else
        pred = 0;
    cout << "The class predicted by the model= " << pred;
}