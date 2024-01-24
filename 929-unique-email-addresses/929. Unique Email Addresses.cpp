class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int i, j, k;
        unordered_set<string> s;

        for (i = 0; i < emails.size(); i++){
            string email = emails[i];

            for (j = 0; j < email.size(); j++){
                if (email[j] == '@') break;
            }

            string temp;

            for (k = 0; k < j; k++){
                if (email[k] == '.'){
                    continue;
                }
                else if (email[k] == '+'){
                    break;
                }
                else temp.push_back(email[k]);
            }

            s.insert(temp + email.substr(j));
        }

        return s.size();
    }
};