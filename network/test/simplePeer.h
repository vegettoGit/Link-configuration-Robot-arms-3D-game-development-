
#include "network.h"
#include <string>

class ISimplePeer
{

public:

   ISimplePeer()                                                    = default;
   ~ISimplePeer()                                                   = default;

   ISimplePeer                       (const ISimplePeer& server)    = delete;
   ISimplePeer&  operator =          (const ISimplePeer& server)    = delete;

   ISimplePeer                       (ISimplePeer&& server)         = delete;
   ISimplePeer&  operator =          (ISimplePeer&& server)         = delete;

   virtual void  createWork          ()                             = 0;
   const char*   getErrorText        ()                             const;
   const char*   getLastSentText     ()                             const;
   const char*   getLastReceivedText ()                             const;

protected:

   virtual void  setError            (const char* text, int error);
   void          setLastSentText     (const char* text, int size);
   void          setLastReceivedText (const char* text, int size);

   std::string   m_lastSentText;
   std::string   m_lastReceivedText;
   Socket        m_socket;
   char          m_errorText[64];

};

