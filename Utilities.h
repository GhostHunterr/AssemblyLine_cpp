#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <string>

namespace sdds
{
    class Utilities
    {
        size_t m_widthField = 1;
        static char m_delimiter;

    public:
        void setFieldWidth(size_t newWidth);                                            // sets the field width of the current object to the value of parameter newWidth
        size_t getFieldWidth() const;                                                   // returns the field width of the current object
        std::string extractToken(const std::string &str, size_t &next_pos, bool &more); // extracts a token from string str referred to by the first parameter

        // Class MemberSS
        static void setDelimiter(char newDelimiter); // sets the delimiter for this class to the character received
        static char getDelimiter();                  // returns the delimiter for this class.
    };

} // namespace sdds

#endif