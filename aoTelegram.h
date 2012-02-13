/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOTELEGRAM_H
#define AOTELEGRAM_H


namespace ao{
namespace core{
//
// Telegram
// (struct template)
// ----------
// + sender : int
// + reciever : int
// + msg : int
// + dispatchTime : double
// + extraInfo : void*
// ----------
//
struct Telegram{
	int sender;
	int reciever;
	int msg;
	double dispatchTime;
	void* extraInfo;
};

}
}
#endif
