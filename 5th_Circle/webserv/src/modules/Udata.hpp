#ifndef UDATA_HPP_
#define UDATA_HPP_

class Udata {
 public:
  Udata();
  virtual ~Udata() = 0;
  bool IsServer();
  bool IsClient();
 protected:
  bool is_server_;
  bool is_client_;
};

#endif
