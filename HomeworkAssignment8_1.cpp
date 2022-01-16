#include <iostream>
using namespace std;
/**
 * MEMBER FUNCTION NAME:
 *    getNumPossibleSigns
 * PURPOSE:
 *    The function takes in a series of addresses in a
 *    string array and compares each of them with the available
 *    letterInventory, returning the number of addresses
 *    that are POSSIBLE to form from the given letterInventory
 * PARAMETER:
 *    string* letterInventory
 *    string* addresses
 *    int length: length of the array, addresses[]
 * RETURN VALUE:
 *    int: the number of possible addresses that can be
 *    formed from your inventory of letters
 */
class Solution
{
    public:
    int getNumPossibleSigns(string*, string*, int);
};

int Solution::getNumPossibleSigns(string* letterInventory, string* addresses, int length)
{
    int addressCount;
    // traverse the array with first for loop
    for(int i = 0; i < length; i++)
    {
        string inventoryCopy = *letterInventory;
        int countSpaces = 0;
        int inInventory = 0;
        string buyerAddress = addresses[i];
        // count number of spaces in string
        for(int x = 0; x < buyerAddress.length(); x++)
        {
            if(buyerAddress[x] == ' ')
            {
                countSpaces++;
            }
        }
        // compare each with set of nested for loops
        // when match is found, set condition value to length to end the inner loop
            /// remove letter from string copy
            /// add +1 to inInventory
        for(int j = 0; j < buyerAddress.length(); j++)
        {
            for(int k = 0; k < inventoryCopy.length(); k++)
            {
                if(inventoryCopy[k] == buyerAddress[j])
                {
                    inInventory++;
                    inventoryCopy.erase(k, 1);
                    k = inventoryCopy.length();
                }
            }
        }
        // subtract total spaces from string length
        // compare inInventory value to str.length()
        // if string length == inInventory value, +1 possible address
        if(inInventory == buyerAddress.length() - countSpaces)
        {
            addressCount++;
        }
    }
    return addressCount;
};
int main()
{
    // Example
    Solution solution;
    string inventory = "aaaadfadfa223432112";
    string addresses[] = {"s1","cad","g2"};
    cout << "Total number of possible addresses: "
         << solution.getNumPossibleSigns(&inventory, addresses, sizeof(addresses)/sizeof(addresses[0]));
    cout << endl;

    Solution solution1;
    string inventory1 = "AAAABCCC123456789";
    string addresses1[] = {"123C","123A","123 ADA"};
    cout << "Total number of possible addresses: "
         << solution1.getNumPossibleSigns(&inventory1, addresses1, sizeof(addresses1)/sizeof(addresses1[0]));
    cout << endl;

    Solution solution2;
    string inventory2 = "ABCDEFGHIJKLMNORSTUVWXYZ1234567890";
    string addresses2[] = {"2 FIRST ST"," 13 PUN ST", "101 AKER"};
    cout << "Total number of possible addresses: "
         << solution2.getNumPossibleSigns(&inventory2, addresses2, sizeof(addresses2)/sizeof(addresses2[0]));
    cout << endl;

    Solution solution3;
    string inventory3 = "ABCDAAST";
    string addresses3[] = {"999 S ST", "A BAD ST", "B BAD ST"};
    cout << "Total number of possible addresses: "
         << solution3.getNumPossibleSigns(&inventory3, addresses3, sizeof(addresses3)/sizeof(addresses3[0]));
    cout << endl;
}
