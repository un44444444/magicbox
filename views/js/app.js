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
      when('/index/:phoneId', {
        templateUrl: 'partials/phone-detail.html',
        controller: 'PhoneDetailCtrl'
      }).
      otherwise({
        redirectTo: '/index'
      });
  }]);
