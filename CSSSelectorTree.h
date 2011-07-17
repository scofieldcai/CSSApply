//
//  CSSSelectorTree.h
//  CSSSample
//
//  Created by Sam Stewart on 7/16/11.
//  Copyright 2011 Float:Right Ltd. All rights reserved.
//
// sam red.green#hello
// red -> .green
//        #hello
// 
// stewart sam red.green#hello
// stew mark red.green#hello
// red.green#hello -> sam -> stewart
//                 -> sam.mark -> stew
// red.green#hello -> lisa -> stewart
// red.green#hello -> sam
// red.green#hello -> sam
// 

// red green blue 

/** 
 @class CSSSelectorTree
 This is a custom data structure which manages a css selector tree. It allows you to lookup views in the tree
 according to their selectors. Each level is caused by a space in a css selector (which represents a descendant relationship)
 at each level we have a CSSSelector which contains a variety of properties (like classes, id, tag type) and a list of child
 nodes.

 */
#import <Foundation/Foundation.h>
#import "CSSSelector.h"

@interface CSSSelectorTree : NSObject {
    //array of CSSSelectors
    NSMutableArray *nodes;
    NSDictionary *rules;
    CSSSelector *selector;
}

@property (readonly, nonatomic) CSSSelector *selector;
@property (readonly, nonatomic) NSDictionary *rules;
@property (readonly, nonatomic) NSMutableArray *nodes;
@property (readonly, nonatomic) NSInteger score;

- (void)sortNodes;

- (id)initWithSelector:(CSSSelector*)selector;
@end
