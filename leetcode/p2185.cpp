

class Solution {
   public:
    /*
     * https://leetcode.com/problems/counting-words-with-a-given-prefix/
     */

    int prefixCount1(std::vector<std::string>& words, std::string pref) {
        int count = 0;
        for (const std::string& word : words) {
            if (word.substr(0, pref.length()) == pref) {
                count++;
            }
        }
        return count;
    }

    int prefixCount(std::vector<std::string>& words, std::string pref) {
        Trie trie;
        for (const std::string& word : words) {
            trie.addWord(word);
        }
        return trie.countPrefix(pref);
    }

   private:
    class Trie {
       private:
        struct Node {
            std::vector<Node*> links;
            int count;

            Node() : links(26, nullptr), count(0) {}
        };

        Node* root;

       public:
        Trie() { root = new Node(); }

        ~Trie() { deleteTrie(root); }

        void addWord(const std::string& word) {
            Node* curr = root;
            for (char c : word) {
                int idx = c - 'a';
                if (curr->links[idx] == nullptr) {
                    curr->links[idx] = new Node();
                }
                curr = curr->links[idx];
                curr->count++;
            }
        }

        int countPrefix(const std::string& pref) {
            Node* curr = root;
            for (char c : pref) {
                int idx = c - 'a';
                if (curr->links[idx] == nullptr) {
                    return 0;
                }
                curr = curr->links[idx];
            }
            return curr->count;
        }

       private:
        void deleteTrie(Node* node) {
            if (node == nullptr) return;
            for (Node* child : node->links) {
                if (child != nullptr) {
                    deleteTrie(child);
                }
            }
            delete node;
        }
    };
};
