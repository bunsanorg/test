%define _builddir   .
%define _sourcedir  .
%define _specdir    .
%define _rpmdir     .

Name:       bunsan_testing
Version:    %{yandex_mail_version}
Release:    %{yandex_mail_release}
Url:        %{yandex_mail_url}

Summary:    bunsan testing classes and functions
License:    GPLv3
Group:      System Environment/Libraries
Packager:   Aleksey Filippov <sarum9in@yandex-team.ru>
Distribution:   Red Hat Enterprise Linux

Requires:       boost >= 1.53.0
BuildRequires:  boost-devel >= 1.53.0
BuildRequires:  bunsan_cmake

BuildRoot:  %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)


%description
Various helpers for unit testing.

%build
cmake . -DCMAKE_INSTALL_PREFIX=/usr \
        -DENABLE_TESTS=NO \
        -DCMAKE_BUILD_TYPE=Release
%{__make} %{?_smp_mflags}


%install
rm -rf %{buildroot}
%{__make} install DESTDIR="%{buildroot}"


%clean
%{__rm} -rf %{buildroot}


%files
%defattr (-,root,root,-)
%{_includedir}/bunsan/testing/*
%{_includedir}/bunsan/testing/filesystem/*
%{_libdir}/libbunsan_testing.so
%{_datadir}/cmake/Modules/BunsanCmake/*.cmake


%changelog
