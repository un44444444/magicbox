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
      when('/about/:areaId', {
        templateUrl: 'partials/about-detail.html',
        controller: 'AboutDetailCtrl'
      }).
      otherwise({
        redirectTo: '/index'
      });
  }]);
