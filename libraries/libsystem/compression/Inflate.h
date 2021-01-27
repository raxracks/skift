#pragma once
#include <libsystem/Common.h>
#include <libsystem/Result.h>
#include <libutils/HashMap.h>
#include <libutils/Vector.h>

// See https://tools.ietf.org/html/rfc1951#section-3.2.3
enum BlockType
{
    BT_UNCOMPRESSED = 0,
    BT_FIXED_HUFFMAN = 1,
    BT_DYNAMIC_HUFFMAN = 2,
};

class Inflate
{
public:
    Result perform(Vector<uint8_t> input, Vector<uint8_t> output);

private:
    void build_fixed_huffman_alphabet();
    void build_huffman_alphabet(Vector<unsigned int> &alphabet, Vector<unsigned int> code_bit_lengths);

    void get_bit_length_count(HashMap<unsigned int, unsigned int> &bit_length_count, const Vector<unsigned int> &code_bit_lengths);
    void get_first_code(HashMap<unsigned int, unsigned int> &firstCodes, HashMap<unsigned int, unsigned int> &bit_length_count);
    void assign_huffman_codes(Vector<unsigned int> assigned_codes, const Vector<unsigned int> &code_bit_lengths, HashMap<unsigned int, unsigned int> &first_codes);

    Vector<unsigned int> _fixed_alphabet;
    Vector<unsigned int> _fixed_code_bit_lengths;
    Vector<unsigned int> _fixed_dist_alphabet;
    Vector<unsigned int> _fixed_dist_code_bit_lengths;
};