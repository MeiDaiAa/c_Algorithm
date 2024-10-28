#include "areSentencesSimilar.cpp"

int main(){
    vector<string>sentence1 = {"great","acting","skills"};
    vector<string>sentence2 = {"fine","drama","talent"};
    vector<vector<string>>smilarPairs = {
        {"great","fine"},
        {"drama","acting"},
        {"skills","talent"}
    };

    Solution sol;
    if(sol.areSentencesSimilar(sentence1, sentence2, smilarPairs)) cout << "true" << endl;
    else cout << "false" << endl;

    return EXIT_SUCCESS;
}