//
//  LuaContext.h
//  DynamOC
//
//  Created by 徐晖 on 2017/1/12.
//  Copyright © 2017年 徐晖. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LuaContext : NSObject

@property (nonatomic, strong) id argumentRegister;
@property (nonatomic, strong) id returnRegister;

+ (NSBundle *)dynamOCBundle;
+ (LuaContext *)currentContext;

- (BOOL)evaluateScript:(NSString *)code;

@end

@class DynamBlock;
@class BlockUpvalue;

void forward_invocation(id target, SEL selector, id invocation);
void forward_block_id_invocation(NSInteger blockID, id invocation);
void forward_block_code_invocation(NSData *code, NSArray<BlockUpvalue *> *upvalues, id invocation);
id get_luacontext();
DynamBlock *create_block(NSInteger blockID, const char* signature);
void free_block(NSInteger blockID);
NSData *dump_block_code(NSInteger blockID);
NSArray<BlockUpvalue *> *dump_block_upvalue(NSInteger blockID);

