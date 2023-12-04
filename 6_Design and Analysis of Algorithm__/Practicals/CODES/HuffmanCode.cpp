#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <time.h>

using namespace std;

// A Huffman tree node
struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};
// Comparison function for priority queue
struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->frequency > r->frequency;
    }
};
// Function to build the Huffman Tree and return the root
HuffmanNode* buildHuffmanTree(const string& text) {
    // Count the frequency of each character in the text
    unordered_map<char, unsigned> freq;
    for (char c : text) {
        freq[c]++;
    }

    // Create a priority queue to store the nodes with their frequencies
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // Create a leaf node for each character and push it to the priority queue
    for (auto& entry : freq) {
        pq.push(new HuffmanNode(entry.first, entry.second));
    }

    // Build the Huffman Tree
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();

        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* internalNode = new HuffmanNode('$', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        pq.push(internalNode);
    }

    // The root of the Huffman Tree is the only node left in the priority queue
    return pq.top();
}

// Traverse the Huffman Tree and store the Programs in a map
void generateHuffmanPrograms(HuffmanNode* root, string Program, unordered_map<char, string>& huffmanPrograms) {
    if (root) {
        if (!root->left && !root->right) {
            huffmanPrograms[root->data] = Program;
        }

        generateHuffmanPrograms(root->left, Program + "0", huffmanPrograms);
        generateHuffmanPrograms(root->right, Program + "1", huffmanPrograms);
    }
}

// EnProgram the input text using Huffman Programs
string enProgramText(const string& text, const unordered_map<char, string>& huffmanPrograms) {
    string enProgramdText = "";
    for (char c : text) {
        enProgramdText += huffmanPrograms.at(c);
    }
    return enProgramdText;
}

// DeProgram the enProgramd text using the Huffman Tree
string deProgramText(HuffmanNode* root, const string& enProgramdText) {
    string deProgramdText = "";
    HuffmanNode* current = root;
    for (char bit : enProgramdText) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!current->left && !current->right) {
            deProgramdText += current->data;
            current = root;
        }
    }
    return deProgramdText;
}

int main() {
    string text;

    cout << "\nEnter the text to be enProgramd: ";
    getline(cin, text);

    clock_t t1,t2;
    float t;
    t1 = clock();
    
    // Build Huffman Tree
    HuffmanNode* root = buildHuffmanTree(text);

    // Generate Huffman Programs
    unordered_map<char, string> huffmanPrograms;
    generateHuffmanPrograms(root, "", huffmanPrograms);

    // EnProgram the text
    string enProgramdText = enProgramText(text, huffmanPrograms);
    cout << "\nEnProgramd Text: " << enProgramdText << endl;

    // DeProgram the text
    string deProgramdText = deProgramText(root, enProgramdText);
    cout << "DeProgramd Text: " << deProgramdText << endl;

    t2 = clock();
    t = (float)(t2-t1) / CLOCKS_PER_SEC;
    cout << "\nProcessing Time is " << t << " seconds.";

    cout << endl;

    return 0;
}
