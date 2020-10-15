#pragma comment(lib,"USBDAQ8.lib")

#define UINT unsigned int
#define USHORT unsigned short
#define UCHAR unsigned char
#define INT int

typedef void *HANDLE;

extern "C" __declspec(dllimport) HANDLE USB8CHDAQ_INIT(void);

extern "C" __declspec(dllimport) void USB8CHDAQ_QUIT(HANDLE DevHandle);

extern "C" __declspec(dllimport) INT USB8CHDAQ_DAQ(HANDLE DevHandle,UINT Channel, UINT Frequency, USHORT Length);

extern "C" __declspec(dllimport) INT USB8CHDAQ_ReadData_Continue(HANDLE DevHandle,INT Len,UCHAR *pData);

extern "C" __declspec(dllimport) INT USB8CHDAQ_ReadData_1FPS(HANDLE DevHandle,INT ChannelNumber,INT len,UCHAR *pData);

extern "C" __declspec(dllimport) INT USB8CHDAQ_DI(HANDLE DevHandle,INT enable);

extern "C" __declspec(dllimport) INT USB8CHDAQ_DO(HANDLE DevHandle,INT low,INT high);

extern "C" __declspec(dllimport) INT USB8CHDAQ_ReadDIData(HANDLE DevHandle,UCHAR *highData,UCHAR *lowData);

extern "C" __declspec(dllimport) INT USB8CHDAQ_DAC(HANDLE DevHandle,UINT Ch0,UINT Ch1,UCHAR mode);

extern "C" __declspec(dllimport) void USB8CHDAQ_Convert(UCHAR *pOrg,double *rData,INT Len,INT ChannelCount);