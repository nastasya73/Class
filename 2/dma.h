// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class Ab_DMA {
	private:
		char * label;
		int rating;
	public:
		Ab_DMA(const char * l = "null", int r = 0) ;
		Ab_DMA(const Ab_DMA & rs);
		virtual ~Ab_DMA() = 0;
		friend std::ostream & operator<<(std::ostream & os, const Ab_DMA & rs);
		virtual void View() const = 0;
};

class baseDMA:public Ab_DMA
{
	private:

	public:
		baseDMA(const char * l = "null", int r = 0) ;
		baseDMA(const baseDMA & rs);
		virtual ~baseDMA();
		baseDMA & operator=(const baseDMA & rs);
		virtual void View() const;
		friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};


class lacksDMA :public Ab_DMA
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
	virtual void View() const;
    friend std::ostream & operator<<(std::ostream & os, 
                                     const lacksDMA & rs);
};


class hasDMA :public Ab_DMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
              int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);  
	virtual void View() const;
    friend std::ostream & operator<<(std::ostream & os, 
                                     const hasDMA & rs);
};

#endif
