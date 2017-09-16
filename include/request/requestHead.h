/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#ifndef REQUESTHEAD_H
#define REQUESTHEAD_H

class requestHead
{
    public:
        /** Default constructor */
        requestHead();
        /** Copy constructor
         *  \param other Object to copy from
         */
        requestHead(const requestHead& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        requestHead& operator=(const requestHead& other);

        /** Access host
         * \return The current value of host
         */
        std::string Gethost() { return host; }
        /** Set host
         * \param val New value to set
         */
        void Sethost(std::string val) { host = val; }
        /** Access user_Agent
         * \return The current value of user_Agent
         */
        std::string Getuser_Agent() { return user_Agent; }
        /** Set user_Agent
         * \param val New value to set
         */
        void Setuser_Agent(std::string val) { user_Agent = val; }
        /** Access accept
         * \return The current value of accept
         */
        std::string Getaccept() { return accept; }
        /** Set accept
         * \param val New value to set
         */
        void Setaccept(std::string val) { accept = val; }
        /** Access accept-Encoding
         * \return The current value of accept
         */
        std::string Getaccept_Encoding() { return accept_Encoding; }
        /** Set accept-Encoding
         * \param val New value to set
         */
        void Setaccept_Encoding(std::string val) { accept_Encoding = val; }
        /** Access accept-Language
         * \return The current value of accept-Language
         */
        std::string Getaccept_Language() { return accept_Language; }
        /** Set accept-Language
         * \param val New value to set
         */
        void Setaccept_Language(std::string val) { accept_Language = val; }
        /** Access connection
         * \return The current value of connection
         */
        std::string Getconnection() { return connection; }
        /** Set connection
         * \param val New value to set
         */
        void Setconnection(std::string val) { connection = val; }

        /** Input function */
        friend std::istream& operator>>(std::istream &in,requestHead& reqstHead);
        /** output function*/
        friend std::ostream& operator<<(std::ostream &out,const requestHead& reqstHead);

    protected:

    private:
        std::string host; //!< Member variable "host"
        std::string user_Agent; //!< Member variable "user_Agent"
        std::string accept;//!< Member variable "accept"
        std::string accept_Encoding; //!< Member variable "accept-Encoding"
        std::string accept_Language; //!< Member variable "accept-Language"
        std::string connection; //!< Member variable "connection"
};

#endif // REQUESTHEAD_H
