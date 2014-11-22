//
//  PPCollectionViewController.h
//  PPToolkit
//
//  Created by Joachim Kret on 23.05.2013.
//  Copyright (c) 2013 Joachim Kret. All rights reserved.
//

#import "PPKeyboardViewController.h"

#import "PSTCollectionView.h"

@interface PPCollectionViewController : PPKeyboardViewController <PSUICollectionViewDelegate, PSUICollectionViewDataSource> {
@protected
    PSUICollectionViewLayout    * _layout;
    PSUICollectionView          * _collectionView;
    
    struct {
        unsigned int clearsSelectionOnViewWillAppear    : 1;
        unsigned int clearsSelectionOnReloadData        : 1;
        unsigned int reloadOnAppearsFirstTime           : 1;
        unsigned int needsReload                        : 1;
    } _PPCollectionViewControllerFlags;
}

@property (nonatomic, readonly, strong) PSUICollectionViewLayout * layout;
@property (nonatomic, readwrite, strong) IBOutlet PSUICollectionView * collectionView;
@property (nonatomic, readwrite, assign) BOOL clearsSelectionOnViewWillAppear;
@property (nonatomic, readwrite, assign) BOOL clearsSelectionOnReloadData;
@property (nonatomic, readwrite, assign) BOOL reloadOnAppearsFirstTime;
@property (nonatomic, readonly, assign, getter = isEmpty) BOOL empty;

+ (Class)defaultCollectionViewClass;
+ (Class)defaultCollectionViewLayoutClass;
+ (Class)defaultCollectionViewCellClass;
+ (NSString *)defaultCollectionViewCellNibName;

- (id)initWithCollectionViewLayout:(PSUICollectionViewLayout *)layout;

- (void)setNeedsReload;
- (BOOL)needsReload;

- (void)reloadIfNeeded;
- (void)reloadIfVisible;
- (void)reloadData;

@end
