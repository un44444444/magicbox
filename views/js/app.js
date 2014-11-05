'use strict';

/* App Module */

var magicboxApp = angular.module('magicboxApp', [
  'ngRoute',

  'magicboxControllers',
  'magicboxFilters',
  'magicboxServices'
]);

magicboxApp.config(['$routeProvider',
  function($routeProvider) {
    $routeProvider.
      when('/index', {
        templateUrl: 'partials/main.html',
        controller: 'MainCtrl'
      }).
      when('/ssq', {
        templateUrl: 'partials/ssq.html',
        controller: 'SsqCtrl'
      }).
      when('/about', {
        templateUrl: 'partials/about.html',
        controller: 'AboutCtrl'
      }).
      when('/ssq/:ssqId', {
        templateUrl: 'partials/ssq-detail.html',
        controller: 'SsqDetailCtrl'
      }).
      otherwise({
        redirectTo: '/index'
      });
  }]);
