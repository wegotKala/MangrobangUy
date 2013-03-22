#include "Project.h"
#include<iostream>
#include<math.h>
#include<cstring>
#include<vector>
#include <stdio.h>
#include<fstream>
#include <algorithm>
#include<string>
#include<sstream>

using namespace std;
Project::Project()
{
    //ctor
}

Project::~Project()
{
    //dtor
}

void Project:: multiples_of_3_and_5(){

  int i=0;
  int temp=0;

  for (i=0;i<1000;i++){


    if (i%3==0|| i%5==0){
        temp=i+temp ;
    }
  }

  cout<< " Sum of multiples of 3 and 5 from 1-1000: "<<temp<<endl;


}

void Project::even_fibonacce(){

 int  c, first = 0, second = 1, next,sum_even=0;


   for ( c = 0 ; ; c++ )
   {

      if ( c <= 1 ){
         next = c;
      }

      else{
         next = first + second;
         first = second;
         second = next;
      }

      if (next%2==0){
        sum_even=sum_even+next;
      }


      if (next>=4000000){
        break;
      }


   }
   cout<< " Sum of even numbers in the fibonacci sequence is:"<<sum_even<<endl;


}

void Project:: largest_prime_factor(){

    long long int num = 600851475143;

    for(int i = 2; i < num; i++){
            if(num % i == 0){
                num = num/i;
                i= i-1;

            }

    }

 cout << "The largest prime is.. " << num <<endl;


}




void Project::largest_palindrome_product() {

    int ans = 0;
    for(int a = 999; a > 1; --a)
        for(int b = a; b > 1; --b){
            int x = a * b;
            int y=x;
            int reverse_x=0;

            while (y){
                    reverse_x=reverse_x*10 +(y%10);
                    y/=10;
            }

	            if(x == reverse_x && x > ans) ans = x;
        }

        cout << "The largest palndrome product is::"<< ans<<endl;


}

void Project::smallest_multiple(){
    int num = 0, divisor;

    cout<< "Please wait. This might take a few seconds....." <<endl;

    do
    {
        num++;
        for(divisor = 1; divisor <=20; divisor++)
        {
                if (!(num%divisor == 0))break;
        }
    } while(divisor<=20);

   cout << "The smallest number divisible by numbers from 1-20 is:"<< num <<endl;


}

 void Project::sum_square_diff(){
        const unsigned int limit = 100;
	    int i;
	    unsigned long long sumOfSquares = 0;
	    unsigned long long squareOfSums = 0;
	    long long diff;

	    for(i=1;i<=limit;i++){
            sumOfSquares += pow((i),2);
            squareOfSums += i;
	    }

	    squareOfSums = pow(squareOfSums, 2);
	    diff = squareOfSums - sumOfSquares;

	    cout<<"Square of sum: " << squareOfSums<<endl;
	    cout<<"Sum of Squares:" << sumOfSquares<<endl;


        cout << "The difference is:"<< diff <<endl;


}


 void Project:: prime_10001st(){
        int MAX=1000000;
        bool p[MAX];

	    memset(p, 1, sizeof(p));
	    int ans = 1000, c = 1;
	    for(int i = 4; i < MAX; i += 2)
                p[i] = 0;
	    for(int i = 3; i < 1001; i += 2)
	        if(p[i]){
	            ++c;
	            for(int j = i * i; j < MAX; j += i) p[j] = 0;
	        }
	        while(c < 10001) c += p[++ans];

        cout << "The 10001st prime is: "<< ans<<endl;

}

 void Project::largest_product_in_series(){
     string str = "73167176531330624919225119674426574742355349194934"
                  "96983520312774506326239578318016984801869478851843"
                  "85861560789112949495459501737958331952853208805511"
                  "12540698747158523863050715693290963295227443043557"
                  "66896648950445244523161731856403098711121722383113"
                  "62229893423380308135336276614282806444486645238749"
                  "30358907296290491560440772390713810515859307960866"
                  "70172427121883998797908792274921901699720888093776"
                  "65727333001053367881220235421809751254540594752243"
                  "52584907711670556013604839586446706324415722155397"
                  "53697817977846174064955149290862569321978468622482"
                  "83972241375657056057490261407972968652414535100474"
                  "82166370484403199890008895243450658541227588666881"
                  "16427171479924442928230863465674813919123162824586"
                  "17866458359124566529476545682848912883142607690042"
                  "24219022671055626321111109370544217506941658960408"
                  "07198403850962455444362981230987879927244284909188"
                  "84580156166097919133875499200524063689912560717606"
                  "05886116467109405077541002256983155200055935729725"
                  "71636269561882670428252483600823257530420752963450";


    int store = 0; // what I need to compare total to later
    int total = 1; // what will be multiplied by inputs from str[]
    int n = 0; // keeps track of single iterations

    for(int i = 0;n<=999;n++) // i = 0 because that's the starting point for place of first number in string (str[0]); because the length is 1 shorter, 999 is the limit
    {
        total = 1; // must be set back to one each successful product loop
        int incr = n + 4; // places for the next 5 after 0

        // A general note: pattern this generates is that the end digit of an even break in groupings will always either be 4 or 9
        // e.g. breaking the loop at position 44, 199, 234 will multiply 5 places properly without error

        if(n == 0) // string starts at 0, must be accounted for especially
        {
            for(;i<=4;i++) // i = str[0] which is then incrmemented to str[4] which is fifth number
            {
                total*=(str[i] - '0'); // takes str[1],str[2],...str[4] and multiplies them together using total as valueholder.

            };

            store = total > store ? total:store; // if total is greater than store, then store = total; simple enough
        };

        for(;i<=incr;i++) // i must be added by 4 now because 0,1,2,3,4 are first five and 1,2,3,4,5 are next
        {

            total*=(str[i] - '0'); // takes str[1],str[2],...str[4] and multiplies them together using total as valueholder.

        };

        store = total > store ? total:store; // if total is greater than store, then store = total; simple enough
        i = (n + 1); // i needs to start at a consecutive n each successful loop
    };


    cout << "The largest product in a series is :"<< store <<endl;

}

 void Project::special_pytho_triplet(){

    int limit = 1000;
	    int a = 0;
	    int b = 1;
	    int c = 999;
	    int tmpC = 999;
	    int sum=0;
	    bool notFound = true;
	    int answer = 0;
	    while(notFound){
	      c = --tmpC;
	      b = 1;
	      while(b < c){
                a = limit - (c + b);
                if((pow(a, 2) + pow(b, 2)) == pow(c, 2)){
                    notFound = false;
                    answer = a * b * c;
                    sum=a+b+c;
                    cout<<a<<" + "<<b <<" + " <<c << " = " << sum<<endl;
                    cout<<a<<" x "<<b <<" x " <<c << " = " << answer<<endl;

	          break;
                }
	        c--;
	        b++;
          }
       }

        cout << "The product of the Phytagorean triplet is :"<< answer <<endl;
}

 void Project::summation_of_primes(){
    int num=1;
	unsigned long long int total=2;
	int divisor;

	bool prime = true ;

	while (num<2000000)
	{
            prime=true;
                if (num<=1)
                    prime=false;
                else if(num==2||num==3)
                    prime=true;
                else if (num%2==0)
                    prime = false ;
                else
            {

                for(divisor=3; divisor <(pow(2000000,0.5));divisor=divisor+2)
                {
                    if (num==divisor)
                        prime=true;
                    else if (num%divisor==0){
                    prime=false;
                    break;
                    }

                }

            }
            if (prime==true){
                total=total+num;
            }
        num=num+2;

	}
        cout << "The sum of all primes below 2 million is :"<< total <<endl;


}

void Project::largest_product_grid(){
    int num_container[20][20] = {
                            { 8,02,22,97,38,15,00,40,00,75,04,05,07,78,52,12,50,77,91, 8},
                            {49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00},
                            {81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65},
                            {52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91},
                            {22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
                            {24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50},
                            {32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
                            {67,26,20,68,02,62,12,20,95,63,94,39,63, 8,40,91,66,49,94,21},
                            {24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
                            {21,36,23, 9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95},
                            {78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14, 9,53,56,92},
                            {16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57},
                            {86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58},
                            {19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40},
                            {04,52, 8,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66},
                            {88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69},
                            {04,42,16,73,38,25,39,11,24,94,72,18, 8,46,29,32,40,62,76,36},
                            {20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,04,36,16},
                            {20,73,35,29,78,31,90,01,74,31,49,71,48,86,81,16,23,57,05,54},
                            {01,70,54,71,83,51,54,69,16,92,33,48,61,43,52,01,89,19,67,48},
                                                                                        };


    int test = num_container[6][8] * num_container[7][9] * num_container[8][10] * num_container[9][11];
    //cout<<test<<endl;


    int start = 0;
    int end = 3;
    long long mul_result = 1;

    vector<long long>final_results;

/////////////////////UP/DOWN/////////////////////
    for(int k=0; k<20; k++)
    {

        for(int j=start; j<=end; j++)
        {
            mul_result = mul_result * num_container[k][j];
            if (j == end)
                final_results.push_back(mul_result);
        }
        mul_result = 1;
        start++;
        end++;

    start = 0;
    end = 3;


        for(int j=start; j<=end; j++)
        {
            mul_result = mul_result * num_container[j][k];
            if (j == end)
                final_results.push_back(mul_result);
        }
        mul_result = 1;
        start++;
        end++;

    start = 0;
    end = 3;

    }
/////////////////////UP/DOWN Ends here//////////////////////



///////////////////Both Ways Diagonal Starts here/////////////////////
int current_row = 0;

for(int i=0; i<=16; i++)
{
    for(int j=0; j<=16; j++)
    {
        current_row = i;
        for(int k=start; k<=end; k++)
        {
            mul_result = mul_result * num_container[current_row][k];
            current_row++;
            if (k==end)
                final_results.push_back(mul_result);
        }
        mul_result = 1;
        start++;
        end++;
    }
    start = 0;
    end = 3;

    for(int j=0; j<=16; j++)
    {
        current_row = i+3;
        for(int k=start; k<=end; k++)
        {
            mul_result = mul_result * num_container[current_row][k];
            current_row--;
            if (k==end)
                final_results.push_back(mul_result);
        }
        mul_result = 1;
        start++;
        end++;
    }
    start = 0;
    end = 3;
}
/////////////////////Both Ways diagonal ends here///////////////////


////////////////////Compare Thning Starts here//////////////////////

long long the_big_one = 0;
for(int i=0; i<final_results.size(); i++)
{
    if (final_results[i] > the_big_one)
        the_big_one = final_results[i];
}

        cout << "The largest product in grid is :"<< the_big_one <<endl;

}

void Project::divisible_triangular_number(){
    int numofdivs = 0;
    int n = 1;
    int tn = 0;
    int max = 0;
    while(numofdivs < 500){
        n++;
        numofdivs = 0;
        tn = n*(n+1)/2;
        for(int i = 1; i < sqrt((float)tn); i++){
            if(tn % i == 0)
            numofdivs++;
        }
        numofdivs *= 2;

        if(floor(sqrt((float)tn)) == sqrt((float)tn))
            numofdivs--;

        if(numofdivs > max){
            max = numofdivs;
        }
    }

        cout << "The first triangle number with over five-hundred divisors is " << tn << endl;

}


void Project::largest_sum(){
    long long int sum = 0;

long long int num[100] = {
37107287533902102,
46376937677490009,
74324986199524741,
91942213363574161,
23067588207539346,
89261670696623633,
28112879812849979,
44274228917432520,
47451445736001306,
70386486105843025,
62176457141856560,
64906352462741904,
92575867718337217,
58203565325359399,
80181199384826282,
35398664372827112,
86515506006295864,
71693888707715466,
54370070576826684,
53282654108756828,
36123272525000296,
45876576172410976,
17423706905851860,
81142660418086830,
51934325451728388,
62467221648435076,
15732444386908125,
55037687525678773,
18336384825330154,
80386287592878490,
78182833757993103,
16726320100436897,
48403098129077791,
87086987551392711,
59959406895756536,
69793950679652694,
41052684708299085,
65378607361501080,
35829035317434717,
94953759765105305,
88902802571733229,
25267680276078003,
36270218540497705,
24074486908231174,
91430288197103288,
34413065578016127,
23053081172816430,
11487696932154902,
63783299490636259,
67720186971698544,
95548255300263520,
76085327132285723,
37774242535411291,
23701913275725675,
29798860272258331,
18495701454879288,
38298203783031473,
34829543829199918,
40957953066405232,
29746152185502371,
41698116222072977,
62467957194401269,
23189706772547915,
86188088225875314,
11306739708304724,
82959174767140363,
97623331044818386,
42846280183517070,
55121603546981200,
32238195734329339,
75506164965184775,
62177842752192623,
32924185707147349,
99518671430235219,
73267460800591547,
76841822524674417,
97142617910342598,
87783646182799346,
10848802521674670,
71329612474782464,
62184073572399794,
66627891981488087,
60661826293682836,
85786944089552990,
66024396409905389,
64913982680032973,
16730939319872750,
94809377245048795,
78639167021187492,
15368713711936614,
40789923115535562,
44889911501440648,
41503128880339536,
81234880673210146,
82616570773948327,
22918802058777319,
77158542502016545,
72107838435069186,
20849603980134001,
53503534226472524
};

    for(int i = 0; i < 100; i++){
        sum = sum + num[i] ;
    }

    char first_ten[20];

    sprintf(first_ten, "%llu", sum);
    first_ten[10] = '\0';

    cout<< "First ten digits of the large sum is: " <<first_ten<<endl;



}

void Project::longest_collatz_sequence(){
    int longest_chain = 0;
    int max = 0;
    int C = 1;
    long long int n ;

    for(int i = 2; i <= 1000000; i++){
        n = i;
        C = 1;
        while(n != 1){
            if(n % 2 == 0)
            n = n/2;
            else
            n = 3*n + 1;
            C++;
        }
        if(max < C){
            max = C;
            longest_chain = i;

        }
    }

    cout<< "Longest Collatz sequence is: " <<longest_chain<<endl;
}




const int MAX_SOLUTIONS = 1000;
typedef unsigned long long Long;
int getSolutions(unsigned long long n);

int Project::getSolutions(unsigned long long n)
{

    Long maxX = 2*n;
    register int solutions=0;
    Long differ;
    long double y;
    Long x;

    for(x = n+1; x<=maxX; x++)
    {
        differ = x-n;

            y = (x*n)/(long double)differ;
            //if(y < x)
               // return solutions;
            if((Long)y == y)
            {
                solutions++;
                //cout<<x<<"\t"<<y<<"\t"<<differ<<endl;

            }

    }



    return solutions;

}

void Project::diophantine_reciprocals_a()
{

    int solutions = 0;
    Long n=2*3*5*7*11*13;
    Long x = 2*3*5*7*11*13;

    while(solutions <= MAX_SOLUTIONS)
    {

        solutions = getSolutions(n);
       // cout<<n<<'\t'<<solutions<<endl;
        //cin.get();
          n+=x;
    }


    cout<< "The least value of n with a distinct solution less than one thousand is: "<<n - x<<endl;


}



void Project::power_digit_sum(){

 string total = "1";

  for (int exp = 1; exp <= 1000; ++exp)
  {
    int carry = 0;



    for (int digit = total.length() - 1; digit >= 0; --digit)
    {
      int product = (total[digit] - '0') * 2 + carry;

      if (product > 9)
      {
        carry = 1;
        product %= 10;
      }
      else
      {
        carry = 0;
      }

      total[digit] = '0' + product;

      if (digit == 0 && carry == 1)
        total.insert(0, "1");
    }
  }

  int sum = 0;

  for (unsigned int digit = 0; digit < total.length(); ++digit)

  sum += total[digit] - '0';

  cout<< "Sum of the digits of 2^1000 is: " <<sum<<endl;


}

void Project::number_letter_counts(){

   int sum=0;
    // Letters of of one, two, three, four, ... nine in ones place

    sum = sum + 9*10*(3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4);

    // Letters of ten, twenty, ... ninety

    sum = sum + 10*3 + 100*(6 + 6 + 5 + 5 + 5 + 7 + 6 + 6);

    // Number of hundreds

    sum = sum + 900*7;

    // Letters of one, two, three, ..., nine in hundreds place

    sum = sum + 100*(3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4);

    // Letters of eleven, twelve...

    sum = sum + 10*(6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8);

    // Letters of and

    sum = sum + (900 - 9)*3;

    // Letters of one thousand

    sum = sum + 11;

   cout<< "Number of letters used is: " <<sum<<endl;
   }

void Project::max_path_sum_one(){
    int size = 15;
    int triangle[15][15] = {
    {75},
    {95, 64},
    {17, 47, 82},
    {18, 35, 87, 10},
    {20, 4, 82, 47, 65},
    {19, 1, 23, 75, 3, 34},
    {88, 2, 77, 73, 7, 63, 67},
    {99, 65, 4, 28, 6, 16, 70, 92},
    {41, 41, 26, 56, 83, 40, 80, 70, 33},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
    { 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23},
    };

    int value, left, right;
    int values[size][size];
    int* last = triangle[size-1];

    int row = size-2;
    int col;

    while (true){
        for (col = 0; col < row+1; col++){
            value = triangle[row][col];
            left = last[col];
            right = last[col+1];

            values[row][col] = value + (left > right ? left : right);
        }

        last = values[row];

        if (row == 0){
            break;
        }

        row--;
    }


  cout<< "Maximum total from top to bottom is: " <<values[0][0]<<endl;
}

void Project::counting_sundays(){
    int Sundays = 0;
    int counter = 0;
    int day = 0;
    int month = 0;
    int year = 1901;
    int dayinmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Years 1900-1904 Jan 1st

    while(year < 2001){
    //Leap years
        if(year % 4 == 0){
            dayinmonth[1] = 29;
        }
        else
        dayinmonth[1] = 28;

        //Sept 26 1991

        month = 0;
        while(month < 12){
        day = 0;
            while(day < dayinmonth[month]){

                if(day == 0 && counter % 7 == 5){
                Sundays++;
                //cout << day << endl << month << endl << year << endl;
                }
            counter++;
            day++;

            }
        month++;
        }
    year++;
    }

   cout<< "No. of Sundays fell on the first of the month during the twentieth century: " <<Sundays<<endl;
   }


void Project::factorial_digit_sum(){
    int n=100;
  int array[1000] = {0};
  array[0] = 1;

  for (int m = 1; m <= n; m++) {

    int buffer[1000] = {0};
    for (int i = 0; i < 1000; i++)
        buffer[i] = array[i] * m;

      for (int i = 0; i < 1000; i++) {
        buffer[i+1] += buffer[i]/10;
            array[i] = buffer[i]%10;
      }
  }

  int sum = 0;
  for (int i = 0; i < 1000; i++)
  sum += array[i];



  cout<< "Sum of the digits in 100! is: " <<sum<<endl;
}


void Project:: name_scores(){
    ifstream cin("names.txt");
    vector<string> names;

    string in, tmp, name;
    cin >> in;

    for(int i=0;i<in.size();i++){
    if(in[i]=='"')continue;
    if(in[i]==',')tmp += ' '; else tmp += in[i];
    }

    stringstream ss(tmp);
    while(ss >> name)names.push_back(name);

    sort(names.begin(),names.end());

    int sum = 0;
    for(int i=0;i<names.size();i++){
    int score = 0;
    for(int j=0;j<names[i].size();j++)score += names[i][j]-'A' + 1;
    sum += score * (i + 1);
    }

    cout << "The total score of all the name in the files is: " << sum << endl;
}


typedef long double BigNum;

int numDigits( BigNum num )
{
    int digits = 1;
    while ( num > 10.0 )
    {
        num *= 0.1f;
        ++digits;
    }
    return digits;
}


void Project:: first_1000_digit_fibonacci(){

    BigNum last = 1;
    BigNum current = 1;
    int term = 2;
    bool error = false;
    int n = 0;

    while ( n < 1000 )
    {
        n = 1;
        BigNum fibbonacci = last + current;
        BigNum num = fibbonacci;
        while ( num > 10.0 )
        {
            num *= 0.1f;
            ++n;
        }
        last = current;
        current = fibbonacci;
        ++term;
    }


    cout << "The first 1000 digit fibonacci number is: " << term<< endl;


}


bool isPrime(int n) {
    int max = (int)(sqrt((double)n));
    for (int i = 2; i <= max; ++i) {
        if (n % i == 0) return false;
    }
    return n >= 2;
}

int solve() {
    int num = 0;
    int sum = 0;
    for (int i = 10; ; ++i){
        int len = 0;
        {
            bool b = true;
            int number = i;
            while (true) {
                if (!isPrime(number)) {
                    b = false;
                    break;
                }
                len++;
                number /= 10;
                if (number == 0) break;
            }
            if (!b) continue;
        }
        {
            bool b = true;
            int number = i;
            while (true) {
                number %= (int)pow(10.0, (double)(len - 1));
                if (!isPrime(number)) {
                    b = false;
                    break;
                }
                len--;
                if (len == 1) break;
            }
            if (!b) continue;
        }
        sum += i;
        num++;
        if (num >= 11) break;
    }
    return sum;
}


void Project:: truncatable_primes(){

    cout << "The sum of the only eleven primes that are truncatable is: " << solve()<< endl;
    }
