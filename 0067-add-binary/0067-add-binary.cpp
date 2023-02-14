class Solution {
public:
    char add(char a, char b, char &carry)
    {
        if(a=='0' && b=='0')
        {
            if(carry=='1')
            {
                carry = '0';
                return '1';
            }
            else
                return '0';
        }

        else if((a=='0' && b=='1') || (a=='1'&&b=='0'))
        {
            if(carry == '1')
                return '0';
            else
                return '1';
        }

        else
        {
            if(carry == '1')
                return '1';
            else
            {
                carry = '1';
                return '0';
            }
        }
    }

    string addBinary(string a, string b) 
    {
        int i=a.size()-1, j=b.size()-1;
        char carry='0';
        string res;
        
        while(i>=0 && j>=0)
        {
            res = add(a[i], b[j], carry)+res;
            i--;
            j--;
        }
        for(; i>=0; i--)
        {
            res = add(a[i], '0', carry)+res;
        }
        for(; j>=0; j--)
        {
            res = add('0', b[j], carry)+res;
        }

        if(carry == '1')
            res = '1'+res;
        return res;
    }
};