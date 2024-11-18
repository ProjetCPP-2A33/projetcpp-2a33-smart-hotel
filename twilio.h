/*#ifndef TWILIO_H
#define TWILIO_H

#include <string>
//#include <curl/curl.h>

namespace twilio {

class Twilio {
public:
    Twilio(const std::string& account_sid, const std::string& auth_token);
    bool send_message(const std::string& to_number, const std::string& from_number, const std::string& message_body, std::string& response);

private:
    std::string account_sid_;
    std::string auth_token_;
};

} // namespace twilio

#endif // TWILIO_H

*/
