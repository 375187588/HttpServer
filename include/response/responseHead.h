/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#ifndef RESPONSEHEAD_H
#define RESPONSEHEAD_H

class responseHead
{
    public:
        /** Default constructor */
        responseHead();
        /** Copy constructor
         *  \param other Object to copy from
         */
         responseHead(const responseHead& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        responseHead& operator=(const responseHead& other);

        /** Access date
         * \return The current value of date
         */
        std::string Getdate() { return date; }
        /** Set date
         * \param val New value to set
         */
        void Setdate(std::string val) { date = val; }
        /** Access server
         * \return The current value of server
         */
        static std::string Getserver() { return server; }
        /** Set server
         * \param val New value to set
         */
        static void Setserver(std::string val) { server = val; }
        /** Access content_Length
         * \return The current value of content_Length
         */
        int Getcontent_Length() { return content_Length; }
        /** Set content_Length
         * \param val New value to set
         */
        void Setcontent_Length(int val) { content_Length = val; }
        /** Access content_Type
         * \return The current value of content_Type
         */
        std::string Getcontent_Type() { return content_Type; }
        /** Set content_Type
         * \param val New value to set
         */
        void Setcontent_Type(std::string val) { content_Type = val; }
        /** Access connection
         * \return The current value of connection
         */
        std::string Getconnection() { return connection; }
        /** Set connection
         * \param val New value to set
         */
        void Setconnection(std::string val) { connection = val; }

        /** Output Function */
        friend std::ostream& operator<<(std::ostream &out,const responseHead& respsHead);

    protected:

    private:
        std::string date; //!< Member variable "date"
        static std::string server; //!< Member variable "server"
        int content_Length; //!< Member variable "content_Length"
        std::string content_Type; //!< Member variable "content_Type"
        std::string connection; //!< Member variable "connection"
};

#endif // RESPONSEHEAD_H
