class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentPathMapping;
        vector<vector<string>>output;
        string pathStr, fileName, fileContent;
        bool firstSpace = false, isOpenBrac = false, isCloseBrac = false;
        for (int i = 0; i < paths.size(); i++) {
            fileName = fileContent = pathStr = "";
            isCloseBrac = isOpenBrac = firstSpace = false;
            
            for (int j = 0; j < paths[i].size(); j++) {
                if (!firstSpace && paths[i][j] != ' ') {
                    pathStr.push_back(paths[i][j]);
                }
                else if (!firstSpace && paths[i][j] == ' ') {
                    firstSpace = true;
                }
                else if (firstSpace && paths[i][j] == ' ') {
                    continue;
                }
                else if (!isOpenBrac && paths[i][j] != '(') {
                    fileName.push_back(paths[i][j]);
                }
                else if (!isOpenBrac && paths[i][j] == '(') {
                    isOpenBrac = true;
                }
                else if (isOpenBrac && paths[i][j] != ')') {
                    fileContent.push_back(paths[i][j]);
                }
                else if (isOpenBrac && paths[i][j] == ')') {
                    contentPathMapping[fileContent].push_back(pathStr + "/" + fileName);
                    fileContent = "";
                    fileName = "";
                    isOpenBrac = false;
                }
            }
        }
        
        for (auto group : contentPathMapping) {
            if (group.second.size() > 1)
                output.push_back(group.second);
        }
        return output;
    }
};