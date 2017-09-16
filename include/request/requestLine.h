/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#ifndef REQUESTLINE_H
#define REQUESTLINE_H

class requestLine
{
    public:
        /** Default constructor */
        requestLine();
        /** Copy constructor
         *  \param other Object to copy from
         */
        requestLine(const requestLine& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        requestLine& operator=(const requestLine& other);

        /** Access method
         * \return The current value of method
         */
        std::string Getmethod() { return method; }
        /** Set method
         * \param val New value to set
         */
        void Setmethod(std::string val) { method = val; }
        /** Access uri
         * \return The current value of uri
         */
        std::string Geturi() { return uri; }
        /** Set uri
         * \param val New value to set
         */
        void Seturi(std::string val) { uri = val; }
        /** Access version
         * \return The current value of version
         */
        std::string Getversion() { return version; }
        /** Set version
         * \param val New value to set
         */
        void Setversion(std::string val) { version = val; }

        /** input function*/
        friend std::istream& operator>>(std::istream &in,requestLine& reqstLine);
        /** output function*/
        friend std::ostream& operator<<(std::ostream &out,const requestLine& reqstLine);

    protected:

    private:
        std::string method; //!< Member variable "method"
        std::string uri; //!< Member variable "uri"
        std::string version; //!< Member variable "version"
};

#endif // requestLine_H
