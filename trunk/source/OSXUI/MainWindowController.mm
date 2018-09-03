//
//  MainWindowController.mm
//  fHashMacUI
//
//  Created by Sun Junwen on 7/15/15.
//  Copyright © 2015 Sun Junwen. All rights reserved.
//

#import "MainWindowController.h"
#import "MainViewController.h"

@interface MainWindowController ()

@end

@implementation MainWindowController

- (void)windowDidLoad {
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
    [self.window setDelegate:self];

}

- (MainViewController *)getMainViewController {
    MainViewController *mainViewController;
    mainViewController = (MainViewController *)self.window.contentViewController;
    return mainViewController;
}

- (BOOL)windowShouldClose:(id)sender {
    MainViewController *mainViewController = [self getMainViewController];
    
    if ([mainViewController isCalculating])
        [mainViewController stopHashCalc:YES];
    
    return ![mainViewController isCalculating];
}

@end
