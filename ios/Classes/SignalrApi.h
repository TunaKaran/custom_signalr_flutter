// Autogenerated from Pigeon (v4.2.5), do not edit directly.
// See also: https://pub.dev/packages/pigeon
#import <Foundation/Foundation.h>
@protocol FlutterBinaryMessenger;
@protocol FlutterMessageCodec;
@class FlutterError;
@class FlutterStandardTypedData;

NS_ASSUME_NONNULL_BEGIN

/// Transport method of the signalr connection.
typedef NS_ENUM(NSUInteger, FLTTransport) {
  FLTTransportAuto = 0,
  FLTTransportServerSentEvents = 1,
  FLTTransportLongPolling = 2,
};

/// SignalR connection status
typedef NS_ENUM(NSUInteger, FLTConnectionStatus) {
  FLTConnectionStatusConnecting = 0,
  FLTConnectionStatusConnected = 1,
  FLTConnectionStatusReconnecting = 2,
  FLTConnectionStatusDisconnected = 3,
  FLTConnectionStatusConnectionSlow = 4,
  FLTConnectionStatusConnectionError = 5,
};

@class FLTConnectionOptions;
@class FLTStatusChangeResult;

@interface FLTConnectionOptions : NSObject
+ (instancetype)makeWithBaseUrl:(nullable NSString *)baseUrl
    hubName:(nullable NSString *)hubName
    queryString:(nullable NSString *)queryString
    hubMethods:(nullable NSArray<NSString *> *)hubMethods
    headers:(nullable NSDictionary<NSString *, NSString *> *)headers
    transport:(FLTTransport)transport;
@property(nonatomic, copy, nullable) NSString * baseUrl;
@property(nonatomic, copy, nullable) NSString * hubName;
@property(nonatomic, copy, nullable) NSString * queryString;
@property(nonatomic, strong, nullable) NSArray<NSString *> * hubMethods;
@property(nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> * headers;
@property(nonatomic, assign) FLTTransport transport;
@end

@interface FLTStatusChangeResult : NSObject
+ (instancetype)makeWithConnectionId:(nullable NSString *)connectionId
    status:(FLTConnectionStatus)status
    errorMessage:(nullable NSString *)errorMessage;
@property(nonatomic, copy, nullable) NSString * connectionId;
@property(nonatomic, assign) FLTConnectionStatus status;
@property(nonatomic, copy, nullable) NSString * errorMessage;
@end

/// The codec used by FLTSignalRHostApi.
NSObject<FlutterMessageCodec> *FLTSignalRHostApiGetCodec(void);

@protocol FLTSignalRHostApi
- (void)connectConnectionOptions:(FLTConnectionOptions *)connectionOptions completion:(void(^)(NSString *_Nullable, FlutterError *_Nullable))completion;
- (void)reconnectWithCompletion:(void(^)(NSString *_Nullable, FlutterError *_Nullable))completion;
- (void)stopWithCompletion:(void(^)(FlutterError *_Nullable))completion;
- (void)isConnectedWithCompletion:(void(^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
- (void)invokeMethodMethodName:(NSString *)methodName arguments:(NSArray<NSString *> *)arguments completion:(void(^)(NSString *_Nullable, FlutterError *_Nullable))completion;
@end

extern void FLTSignalRHostApiSetup(id<FlutterBinaryMessenger> binaryMessenger, NSObject<FLTSignalRHostApi> *_Nullable api);

/// The codec used by FLTSignalRPlatformApi.
NSObject<FlutterMessageCodec> *FLTSignalRPlatformApiGetCodec(void);

@interface FLTSignalRPlatformApi : NSObject
- (instancetype)initWithBinaryMessenger:(id<FlutterBinaryMessenger>)binaryMessenger;
- (void)onStatusChangeStatusChangeResult:(FLTStatusChangeResult *)statusChangeResult completion:(void(^)(NSError *_Nullable))completion;
- (void)onNewMessageHubName:(NSString *)hubName message:(NSString *)message completion:(void(^)(NSError *_Nullable))completion;
@end
NS_ASSUME_NONNULL_END