#ifndef NtuTool_Common_UserParametersManager_h
#define NtuTool_Common_UserParametersManager_h

#include <map>
#include <string>

#define SET_USER_PARAMETER(NAME) setUserParameter(#NAME,NAME);
#define GET_USER_PARAMETER(NAME) getUserParameter(#NAME,NAME);
#define ASS_USER_PARAMETER(NAME,VALUE) setUserParameter(#NAME,NAME=VALUE);

class UserParametersManager {

 public:

  UserParametersManager();
  virtual ~UserParametersManager();

  void setConfiguration( const std::string& file );
  void setUserParameter( const std::string& key,
                         const std::string& val );
  template <class T>
  void setUserParameter( const std::string& key,
                         const           T& val );
  void setUserParameter( const std::string& key,
                         const        bool& val );
  const std::string& getUserParameter( const std::string& key ) const;
  template <class T>
  void               getUserParameter( const std::string& key,
                                                       T& val ) const;
  void               getUserParameter( const std::string& key,
                                                    bool& val ) const;
  template <class T>
  T                  getUserParameter( const std::string& key ) const;

  void dumpAll( std::ostream& os ) const;

 private:

  UserParametersManager           ( const UserParametersManager& t ) = delete;
  UserParametersManager& operator=( const UserParametersManager& t ) = delete;

  std::map<std::string,std::string> userParameters;

};

#include "NtuTool/Common/interface/UserParametersManager.hpp"

#endif // NtuTool_Common_UserParametersManager_h
