// dma.cpp --dma class methods
#include "dma.h"
#include <cstring>

Ab_DMA::Ab_DMA(const char * l, int r) 
{
	label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

Ab_DMA::Ab_DMA(const Ab_DMA & rs)
{
	label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

Ab_DMA::~Ab_DMA()
{
	delete [] label;
}

std::ostream & operator<<(std::ostream & os, const Ab_DMA & rs)
{
	os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

void Ab_DMA::View() const
{
	std::cout << *this;
}

// baseDMA methods
baseDMA::baseDMA(const char * l, int r) : Ab_DMA(l, r)
{
}

baseDMA::baseDMA(const baseDMA & rs) : Ab_DMA(rs)
{
}

baseDMA::~baseDMA()
{   
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;
    Ab_DMA::operator=(rs);
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    //Ab_DMA::operator<<(os, rs);
	os << (const Ab_DMA &) rs;
    return os;
}

void baseDMA::View() const
{
	std::cout << *this;
}
	

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
    : Ab_DMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
    : Ab_DMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const Ab_DMA &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

void lacksDMA::View() const
{
	std::cout << *this;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
         : Ab_DMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs)
         : Ab_DMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
         : Ab_DMA(hs)  // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    Ab_DMA::operator=(hs);  // copy base portion
    delete [] style;         // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const Ab_DMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}


void hasDMA::View() const
{
	std::cout << *this;
}