%global packname msm
%global packrel 1

Name:             R-%{packname}
Version:          0.8.2
Release:          2%{?dist}
Source0:          ftp://cran.r-project.org/pub/R/contrib/main/%{packname}_%{version}.tar.gz
Source1:          README_License_msm
License:          GPLv2+
URL:              http://cran.r-project.org/web/packages/msm/
Group:            Applications/Engineering
Summary:          Multi-state Markov and hidden Markov models in continuous time
BuildRequires:    R-devel, tetex-latex, R-mvtnorm
BuildRoot:        %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
Requires(post):   R
Requires(postun): R
Requires:         R

%description
Functions for fitting general continuous-time Markov and hidden Markov
multi-state models to longitudinal data.  Both Markov transition rates
and the hidden Markov output process can be modelled in terms of
covariates.  A variety of observation schemes are supported, including
processes observed at arbitrary times, completely-observed processes,
and censored states.

%prep
%setup -q -c -n %{packname}
# Fix some permissions and formats
# find . -type f -perm 755 -exec chmod 644 {} \;
find . -type f -name '*.[hc]' -exec chmod 644 {} \;

# Fix the encoding of the NEWS file
chmod 644 %{packname}/inst/NEWS
iconv -f ISO88591 -t UTF8 -o NEWS %{packname}/inst/NEWS
mv -f NEWS %{packname}/inst

%build

%install
rm -rf $RPM_BUILD_ROOT

# Specific installation procedure for R
mkdir -p $RPM_BUILD_ROOT%{_libdir}/R/library
%{_bindir}/R CMD INSTALL -l $RPM_BUILD_ROOT%{_libdir}/R/library %{packname}

# Temporary fix for the license issue (https://bugzilla.redhat.com/show_bug.cgi?id=498845#c1)
install -m 644 %{SOURCE1} $RPM_BUILD_ROOT%{_libdir}/R/library/%{packname}

# Remove the temporary object files
test -d %{packname}/src && (cd %{packname}/src; rm -f *.o *.so)

# Remove the generic cascading style sheet for R
rm -rf $RPM_BUILD_ROOT%{_libdir}/R/library/R.css


%check
%{_bindir}/R CMD check %{packname}

%clean
rm -rf $RPM_BUILD_ROOT

%post
%{_R_make_search_index}

%postun
%{_R_make_search_index}

%files
%defattr(-, root, root, -)
%dir %{_libdir}/R/library/%{packname}
%doc %{_libdir}/R/library/%{packname}/README_License_msm
%doc %{_libdir}/R/library/%{packname}/latex
%doc %{_libdir}/R/library/%{packname}/data
%doc %{_libdir}/R/library/%{packname}/doc
%doc %{_libdir}/R/library/%{packname}/html
%doc %{_libdir}/R/library/%{packname}/man
%doc %{_libdir}/R/library/%{packname}/DESCRIPTION
%doc %{_libdir}/R/library/%{packname}/NEWS
%{_libdir}/R/library/%{packname}/CONTENTS
%{_libdir}/R/library/%{packname}/INDEX
%{_libdir}/R/library/%{packname}/NAMESPACE
%{_libdir}/R/library/%{packname}/Meta
%{_libdir}/R/library/%{packname}/R
%{_libdir}/R/library/%{packname}/R-ex
%{_libdir}/R/library/%{packname}/help
%{_libdir}/R/library/%{packname}/libs/%{packname}.so

%changelog
* Sat Jun 06 2009 Denis Arnaud <denis.arnaud_fedora@m4x.org> 0.8.2-2
- Altered the license so as to reflect upstream, after clarification with them

* Sun May 03 2009 Denis Arnaud <denis.arnaud_fedora@m4x.org> 0.8.2-1
- Initial package creation
