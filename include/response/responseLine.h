/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#ifndef RESPONSELINE_H
#define RESPONSELINE_H

class responseLine
{
    public:
        /** Default constructor */
        responseLine();
        /** Copy constructor
         *  \param other Object to copy from
         */
         responseLine(const responseLine& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        responseLine& operator=(const responseLine& other);

        /** Access version
         * \return The current value of version
         */
        std::string Getversion() { return version; }
        /** Set version
         * \param val New value to set
         */
        void Setversion(std::string val) { version = val; }
        /** Access statusCode
         * \return The current value of statusCode
         */
        int GetstatusCode() { return statusCode; }
        /** Set statusCode
         * \param val New value to set
         */
        void SetstatusCode(int val) { statusCode = val; }
        /** Access status
         * \return The current value of status
         */
        std::string Getstatus() { return status; }
        /** Set status
         * \param val New value to set
         */
        void Setstatus(std::string val) { status = val; }

        /** Output Fuction */
        friend std::ostream& operator<<(std::ostream &out,const responseLine& respsLine);

    protected:

    private:
        std::string version; //!< Member variable "version"
        int statusCode; //!< Member variable "statusCode"
        std::string status; //!< Member variable "status"
};

#endif // RESPONSELINE_H
