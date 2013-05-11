//
//  RMLinkedInSDK.h
//  MasterShareSDK
//
//  Created by Ramiro Guerrero & Marco Graciano on 5/2/13.
//    Copyright (c) 2013 Weston McBride
//
//    Permission is hereby granted, free of charge, to any
//    person obtaining a copy of this software and associated
//    documentation files (the "Software"), to deal in the
//    Software without restriction, including without limitation
//    the rights to use, copy, modify, merge, publish,
//    distribute, sublicense, and/or sell copies of the
//    Software, and to permit persons to whom the Software is
//    furnished to do so, subject to the following conditions:
//
//    The above copyright notice and this permission notice
//    shall be included in all copies or substantial portions of
//    the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
//    KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//    WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
//    PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
//    OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
//    OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


#import "AFOAuth2Client.h"

@protocol LinkedInDelegate <NSObject>
@optional
-(void)performLinkedInLoginFromHandle;
@end


@interface RMLinkedInSDK : AFOAuth2Client<UIWebViewDelegate>

@property (nonatomic, retain) NSDictionary *params;
@property (nonatomic, retain) AFOAuthCredential *credential;
@property (nonatomic, strong) NSObject <LinkedInDelegate> *loginDelegate;
@property (nonatomic, strong) UIWebView *webView;

+ (RMLinkedInSDK *)sharedClient;
-(void)authenticateWithScopes:(NSString *)scopes;

//PEOPLE
//Profile API, more info: http://developer.linkedin.com/documents/profile-api
-(void)getCurrentUserProfileWithFieldSelectors:(NSString *)fieldSelectors AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)getUserProfileWithMemberId:(NSString *)memberID WithFieldSelectors:(NSString *)fieldSelectors AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)getUserProfileWithProfileURL:(NSString *)profileURL WithFieldSelectors:(NSString *)fieldSelectors AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
//Connections API, more info: http://developer.linkedin.com/documents/connections-api
-(void)getCurrentUserConnectionsWithParameters:(NSDictionary *)params WithFieldSelectors:(NSString *)fieldSelectors AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
//People Search API, more info: http://developer.linkedin.com/documents/people-search-api
-(void)getPeopleSearchWithParameters:(NSDictionary *)params WithFieldSelectors:(NSString *)fieldSelectors AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;

//GROUPS
//Groups API, more info: http://developer.linkedin.com/documents/groups-api
-(void)getGroupProfileDetailsWithGroupId:(NSString *)groupID WithFieldSelectors:(NSString *)fieldSelectors AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)getCurrentUserGroupMembershipsWithFieldSelectors:(NSString *)fieldSelectors WithParameters:(NSDictionary *)params AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)getCurrentUserShowGroupSettingsWithGroupId:(NSString *)groupID WithFieldSelectors:(NSString *)fieldSelectors AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)putJoinGroupWithGroupId:(NSString *)groupID AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)deleteLeaveGroupWithGroupId:(NSString *)groupID AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)getGroupPostsWithGroupId:(NSString *)groupID WithParameters:(NSDictionary *)params WithFieldSelectors:(NSString *)fieldSelectors AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)getCurrentUserGroupPostsWithGroupId:(NSString *)groupID WithParameters:(NSDictionary *)params WithFieldSelectors:(NSString *)fieldSelectors AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)postCreateDiscussionPostInGroupWithGroupId:(NSString *)groupID WithBody:(NSString *)body AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)getPostDetailsWithPostId:(NSString *)postID WithFieldSelectors:(NSString *)fieldSelectors AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)getPostCommentsWithPostId:(NSString *)postID WithFieldSelectors:(NSString *)fieldSelectors WithParameters:(NSDictionary *)params AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)putLikeUnlikePostWithPostId:(NSString *)postID WithIsLiked:(NSString *)isLiked AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)putFollowUnfollowPostWithPostId:(NSString *)postID WithIsFollowing:(NSString *)isFollowing AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)putFlagPostWithPostId:(NSString *)postID WithFlag:(NSString *)flag AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)deletePostOrFlagAsInappropriateWithPostId:(NSString *)postID AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)getCommentWithCommentId:(NSString *)commentID WithFieldSelectors:(NSString *)fieldSelectors AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)postAddCommentToPostWithPostId:(NSString *)postID WithComment:(NSString *)comment AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;
-(void)deleteCommentOrFlagAsInappropriateWithCommentId:(NSString *)commentID AndWithDelegate:(NSObject <LinkedInDelegate> *)delegate;


@end
