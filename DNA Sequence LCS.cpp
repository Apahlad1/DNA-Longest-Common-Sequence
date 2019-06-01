#include<iostream>
#include<string>
using namespace std;
#define MAX 100 // set the length of my string to 100 to test the DNA strands

int l [MAX][MAX]; // this will hold string x and y's length of the LCS

string LongComSeq (string s1 , string s2, int m, int n)
// string LongComSeq is a recursive function that we will call later to find LCS
{
	if (m == 0 || n == 0) // the string starts from 0 
	return string(); // this just returns 0
	// this is in case the function has reached the end of the string, which returns nothing
	if (s1[m-1]==s2[n-1]) // this checks if string x and y's letter matches
	{
		return LongComSeq(s1,s2, m-1,n-1) + s1[m-1]; 
	}
	
	if (l[m-1][n] > l [m][n-1])
	return LongComSeq(s1,s2,m-1,n);
	
	else
	
	return LongComSeq(s1,s2,m,n-1);
}

void findLength(string s1, string s2, int m, int n)
{ // this function with determine the length of the resulting sequence after comparisons
	for (int i = 1; i <= m ; i++)
	{
		for (int j=1; j <=n ; j++)
		{
			if (s1[i-1] == s2[j-1])
			l[i][j] = l [i -1][j-1] + 1;		
		else
		l[i][j] = max(l[i-1][j], l[i][j-1]);	
			
		}
	}
}
	
	
	
int main ()
{
for (int i = 1; i <= 12 ; i++)
{

string a;
string b;
			// Sample DNA Sequences to use for comparisions
		 // Sequence#1 :  AGCCTAGCTTCAGTCAGAAATCGCAGGGTGACAG
		// Sequence#2 :  TGTTTAACGTATCCAGTCTACGGTCGACGAGGTAC
		//Sequence#3 :  GGTTAACGTACTGATTCATAGCCCTATTAAGGACA
		//Sequence#4 :  CCTAGTCCGTGTATCTACTCAGCTAAGAGTAAGTT
cout << "\n Enter the first DNA Strand Sequence :   \n" << endl;
cin >> a; 
		
cout << "\n Enter the second DNA Strand Sequence : \n" << endl;
cin >> b;
int m = a.length();
int n = b.length();

findLength(a,b,m,n);
cout << "\n THE LONGEST COMMON SEQUENCE IS :  " << LongComSeq(a,b,m,n) << "\n";
}	
return 0;
}
