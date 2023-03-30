class Solution {
public:
    string simplifyPath(string path) {
        int index = 0;
        vector<string> names;
        while (index < path.size()) {
            int next_index = path.find("/", index + 1);
            if (next_index == std::string::npos) {
                next_index = path.size();
            }
            string name = path.substr(index + 1, next_index - index - 1);
            if (name == ".") {
                // pass
            } else if (name == "..") {
                if (!names.empty()) {
                    names.pop_back();
                }
            } else if (name != "") {
                names.push_back(name);
            }
            index = next_index;
        }

        string s;
        if (!names.empty()) {
            for (string name: names) {
                s += "/";
                s += name;
            }
        } else {
            s = "/";
        }
        return s;
    }
};
