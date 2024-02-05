#include <iostream>
#include <string>
#include <vector>

class Cipher {
private:
    std::vector<int> key;
    std::vector <std::string> words;
    std::string msg;

public:
    void setKey(std::vector<int>& newKey)
    {
        key = newKey;
    }

    void Space(std::string& newMsg)
    {
        std::string word;
        for (auto&& i : newMsg)
        {
            if (i != ' ')
            {
                word += i;
            }
            else {
                words.push_back(word);
                word.clear();
            }
        }
        words.push_back(word);
    }

    bool test(std::string& newMsg, std::vector<int>& newKey)
    {
        Space(newMsg);
        if (words.size() == newKey.size())
        {
            int num1 = 1;
            int num2 = 1;
            int num3;
            for (int i = 0; i < newKey.size(); ++i)
            {
                for (int j = 0; j < key.size(); ++j)
                {
                    if (key[j] == num2)
                    {
                        break;
                    }
                    else if (j == newKey.size() - 1)
                    {
                        return false;
                    }
                }
                num3 = num2;
                num2 = num1 + num2;
                num1 = num3;
            }
            return true;
        }
        return false;
    }

    std::string Encode(std::string& newMsg) {
        FibCipher(newMsg, false);
        msg.resize(msg.size() - 1);
        return msg;
    }

    std::string Decode(std::string& newMsg) {
        FibCipher(newMsg, true);
        return msg;
    }

    void FibCipher(std::string& newMsg, bool flag)
    {
        words.clear();
        msg.clear();
        std::vector <std::string> ans(key.size());
        if (!test(newMsg, key))
        {
            std::cout << "Error data";
            std::exit(0);
        }
        int num1 = 1;
        int num2 = 1;
        int num3;
        for (int i = 0; i < key.size(); ++i)
        {
            for (int j = 0; j < key.size(); ++j)
            {
                if (key[j] == num2)
                {
                    if (flag)
                        ans[i] = words[j];
                    else
                        ans[j] = words[i];
                }
            }
            num3 = num2;
            num2 = num1 + num2;
            num1 = num3;
        }
        for (auto&& n : ans)
        {
            msg += n + ' ';
        }
    }
};

int main() {
    std::vector <int> key = { 2, 8, 5, 1, 3 };
    std::string Msg = "Hello, my name is Ivan.";
    std::string EncodedMsg;
    std::string DecodedMsg;

    Cipher enc;
    enc.setKey(key);

    EncodedMsg = enc.Encode(Msg);
    std::cout << EncodedMsg << std::endl;

    DecodedMsg = enc.Decode(EncodedMsg);
    std::cout << DecodedMsg;

    return 0;
}