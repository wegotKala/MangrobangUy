#include <iostream>
void projecy::largest_product_in_series()
{
ifstream ReadFile;
string line, str;
string numbers = "";
int index = 0;
int temp = 0;
int y = 0;
int product = 1;
int product2 = 1;
int getnumber[5];
int highestproduct[5];
while(ReadFile.good())
{
getline(ReadFile, line);
str = line;
numbers += str;
}
string a;
for(int i = 0; i < 1000 - 4;i++)
{
product2 = 1;
index = i;
for(int k = 0; k < 5; k++)
{
a = numbers.at(index);
stringstream(a) >> temp;
y = temp;
getnumber[k] = y;
product2 *= getnumber[k];
index++;
}
if(product < product2)
{
product = product2;
for(int k = 0; k < 5; k++)
{
highestproduct[k] = getnumber[k];
}
}
}
cout << product << endl;
}
