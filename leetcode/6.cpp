// Question:
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
// (you may want to display this pattern in a fixed font for better legibility)
//
// Case:
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// ansert:
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

class Solution 
{
public:
    string convert(string s, int nRows) 
    {
    	if (s.empty())
    	{
    		return s;
    	}

        if (nRows == 1)
        {
            return s;
        }

        vector<vector<char> > vec;
        for (int i = 0; i < nRows; i++)
        {
            vector<char> tmp;
            vec.push_back(tmp);
        }

        int n = nRows * 2 - 2;
        for (int j = 0; j < s.size(); j++)
        {
            int t = j % n;
			char ch = s[j];
            if (t <= nRows - 1)
            {
                vec[t].push_back(ch);
            }
            else
            {
                vec[n - t].push_back(ch);
            }
        }

        char str[1000];
        int p = 0;
        for (int k = 0; k < vec.size(); k++)
        {
            vector<char>tmp = vec[k];
            for (int m = 0; m < tmp.size(); m++)
            {
                str[p++] = tmp[m];
            }
        }

        str[p] = '\0';

		string result(str);
        return result;
    }
};