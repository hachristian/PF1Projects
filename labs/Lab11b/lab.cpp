#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

// Interface for SafeArray class
//--------------------------------
const int SIZE = 20;
class SafeArray
{
public:
   SafeArray();
   SafeArray(const SafeArray & copy);
   ~SafeArray();

   bool GetElement(const int i, float & Value) const;
   bool SetElement(const int i, float Value);
   bool ReadArray(const string Filename);
   bool WriteArray(const string Filename) const;
   void Print() const;
   void Randomize();
   void GetMinimum();
   void GetMaximum();

private:
   float Array[SIZE];
};

// Implementation for SafeArray class
//-----------------------------------
SafeArray::SafeArray()
{
   for (int i = 0; i < SIZE; i++)
      Array[i] = 0;
}

SafeArray::SafeArray(const SafeArray & copy)
{
   for (int i = 0; i < SIZE; i++)
      Array[i] = copy.Array[i];
}

SafeArray::~SafeArray()
{
}

bool SafeArray::GetElement(const int i, float & Value) const
{
   bool Success = false;
   if ((i >= 0) && (i < SIZE))
   {
      Success = true;
      Value = Array[i];
   }
   return Success;
}

bool SafeArray::SetElement(const int i, float Value)
{
   bool Success = false;
   if ((i >= 0) && (i < SIZE))
   {
      Success = true;
      Array[i] = Value;
   }
   return Success;
}

bool SafeArray::ReadArray(const string Filename)
{
   ifstream infile;
   infile.open(Filename.c_str());
   if (infile.fail())
      return false;

   for (int i = 0; i < SIZE; i++)
      infile >> Array[i];
   infile.close();
   return true;
}

bool SafeArray::WriteArray(const string Filename) const
{
   ofstream outfile;
   outfile.open(Filename.c_str());
   if (outfile.fail())
      return false;

   for (int i = 0; i < SIZE; i++)
      outfile << Array[i] << endl;
   outfile.close();
   return true;
}

void SafeArray::Print() const
{
   for (int i = 0; i < SIZE; i++)
      cout << "Array[" << i << "] = " << Array[i] << endl;
}
void SafeArray::Randomize()
{
   for (int i = 0; i < SIZE; i++)
   {
      float value = (random() % 100) / 100.0; 
      SetElement(i, value);
   }
   Print();
}
void SafeArray::GetMinimum()
{
   float min;
   GetElement(0, min);
   for (int i = 1; i < SIZE; i++)
   {
      float value; 
      GetElement(i, value);
      if (value < min)
         min = value;
   }
   cout << "min value = " << min << endl;
}
void SafeArray::GetMaximum()
{
   float max;
   GetElement(0, max);
   for (int i = 1; i < SIZE; i++)
   {
      float value; 
      GetElement(i, value);
      if (value > max)
         max = value;
   }
   cout << "max value = " << max << endl;

}

// Program to demonstrate SafeArray class
//---------------------------------------
int main()
{
   SafeArray data1;
   // randomize data
   data1.Randomize();
   data1.Randomize();
   
   // Find minimum value
   data1.GetMinimum();

   // Find maximum value
   data1.GetMaximum();


   return 0;
}